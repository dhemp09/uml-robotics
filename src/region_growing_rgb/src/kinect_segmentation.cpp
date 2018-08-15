#include <ros/ros.h>
#include <iostream>
#include <vector>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/search/search.h>
#include <pcl/search/kdtree.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/filters/passthrough.h>
#include <pcl/segmentation/region_growing_rgb.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/conversions.h>
#include <pcl_ros/transforms.h>
#include <pcl_ros/impl/transforms.hpp>	
#include <tf/transform_listener.h>
#include <tf2_ros/transform_listener.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>

using namespace std;

ros::Publisher pub;
ros::Publisher marker_pub;
tf::TransformListener* tfListener;
pcl::PointCloud<pcl::PointXYZRGB>::Ptr pclCloud;
pcl::PointCloud<pcl::PointXYZRGB> objectCenters;

void distanceFilter(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud)
{
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr resCloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    *resCloud = *cloud;

    for(size_t i = 0; i < cloud->points.size(); i++)
    {
        if(!(cloud->points[i].z < 2.0) && !(cloud->points[i].z > 0.1) )
        {
            resCloud->points[i].r = 0;
            resCloud->points[i].g = 0;
            resCloud->points[i].b = 0;
        }
    }

    pcl::PointCloud<pcl::PointXYZRGB>::Ptr tmp(resCloud);
    pclCloud = tmp;
}


void cloud_cb(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr input){ 

  //Planar segmentation algorithm
  pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
  pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
  // Create the segmentation object
  pcl::SACSegmentation<pcl::PointXYZRGB> seg;
  // Optional
  seg.setOptimizeCoefficients (true);
  // Mandatory
  seg.setModelType (pcl::SACMODEL_PLANE);
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setDistanceThreshold (0.01);
  seg.setInputCloud (input);
  seg.segment (*inliers, *coefficients);
  if (inliers->indices.size () == 0)
  {
    PCL_ERROR ("Could not estimate a planar model for the given dataset.");
  }
  //std::cerr << "Model coefficients: " << coefficients->values[0] << " " 
  //                                    << coefficients->values[1] << " "
  //                                    << coefficients->values[2] << " " 
  //                                    << coefficients->values[3] << std::endl;

    pcl::IndicesPtr indices (new vector <int>);
    pcl::PassThrough<pcl::PointXYZRGB> pass;
    pass.setInputCloud (input);
    //pass.setInputCloud (cloud);
    pass.setFilterFieldName ("z");
    pass.setFilterLimits (0.0, 1.5);
    pass.filter (*indices);

    vector<bool> boolIndices(input->points.size());
    for (int i = 0; i < indices->size(); i++)
       boolIndices[(*indices)[i]] = true;
    for (int i = 0; i < inliers->indices.size(); i++)
       boolIndices[inliers->indices[i]] = false;
    pcl::IndicesPtr segmentedIndices(new vector<int>);
    for (int i = 0; i < boolIndices.size(); i++)
       if (boolIndices[i])
           segmentedIndices->push_back(i);
   
    //region growing RGB algorithm
    pcl::search::Search <pcl::PointXYZRGB>::Ptr tree =
    boost::shared_ptr<pcl::search::Search<pcl::PointXYZRGB> > (new pcl::search::KdTree<pcl::PointXYZRGB>);
    pcl::RegionGrowingRGB<pcl::PointXYZRGB> reg;
    reg.setInputCloud (input);
    //reg.setInputCloud (cloud);
    reg.setIndices (segmentedIndices);
    reg.setSearchMethod (tree);
    reg.setDistanceThreshold (10);
    reg.setPointColorThreshold (75);
    reg.setRegionColorThreshold (5);
    reg.setMinClusterSize (400);

    vector <pcl::PointIndices> clusters;
    reg.extract (clusters);
    //std::cerr << clusters.size();
    pcl::PointCloud <pcl::PointXYZRGB>::Ptr colored_cloud = reg.getColoredCloud ();
	
    //distanceFilter(colored_cloud);
    pclCloud = colored_cloud;
    pcl::PointCloud <pcl::PointXYZRGB> object_cloud;
    for(int i = 0; i < objectCenters.points.size(); i++)
    	for(int j = 0; j < clusters.size(); j++)
		for(int k = 0; k < clusters[j].indices.size(); k++)
				if(objectCenters.points[i].x == colored_cloud->points[clusters[j].indices[k]].x
				&& objectCenters.points[i].y == colored_cloud->points[clusters[j].indices[k]].y
				&& objectCenters.points[i].z == colored_cloud->points[clusters[j].indices[k]].z){
					objectCenters.points[i].r = colored_cloud->points[clusters[j].indices[k]].r;
					objectCenters.points[i].g = colored_cloud->points[clusters[j].indices[k]].g;
					objectCenters.points[i].b = colored_cloud->points[clusters[j].indices[k]].b;
				
				}
					

    for(int i = 0; i < objectCenters.points.size(); i++){
	for(int j = 0; j < pclCloud->points.size(); j++){
		if (pclCloud->points[j].r == objectCenters.points[i].r &&
		pclCloud->points[j].g == objectCenters.points[i].g &&
		pclCloud->points[j].b == objectCenters.points[i].b)
			object_cloud.push_back(pclCloud->points[j]);
	}
    }
 

    //output region data as sensor_msgs::PointCloud2
    sensor_msgs::PointCloud2 output;
    pcl::toROSMsg(object_cloud, output);
    //pcl::toROSMsg(*pclCloud, output);
    output.header.frame_id = input->header.frame_id;
    pub.publish(output);   
    
}

int main (int argc, char** argv)
{
  ros::init(argc, argv, "pclDataSubscriber");
  ros::NodeHandle n;
  tfListener = new tf::TransformListener();
  ros::Subscriber sub = n.subscribe("/camera/depth_registered/points", 1, cloud_cb);
  objectCenters = *(ros::topic::waitForMessage<pcl::PointCloud<pcl::PointXYZRGB> >("/object_XYZ_centers", n));
  pub = n.advertise<sensor_msgs::PointCloud2>("/kinect_segmentation", 1);
  ros::spin();

  return (0);
}
