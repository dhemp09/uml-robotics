#include <ros/ros.h>
#include <iostream>
#include <vector>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/search/search.h>
#include <pcl/search/kdtree.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/filters/passthrough.h>
#include <pcl/segmentation/region_growing.h>
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
#include <cob_perception_msgs/DetectionArray.h>
#include <cob_perception_msgs/Detection.h>
#include <cob_perception_msgs/Rect.h>
#include <cob_perception_msgs/Mask.h>
#include <pcl/features/normal_3d.h>
#include <pcl/segmentation/region_growing_rgb.h>

using namespace std;

ros::Publisher pub;

typedef pcl::PointCloud<pcl::PointXYZRGB> pclCloud;



pclCloud cloud;

bool cloudCBCalled = false;
bool regionGrowingSeg = false;
bool regionRGBSeg = false;


//pcl_cb gets PointCloud data from /camera/depth_registered/points and creates a PointCloud
//of segmented regions, using planar segmentation and either region growing with normals
//or region growing RGB segmentation
void pcl_cb(const pclCloud::ConstPtr& input){
	if(input->size() != 0){

//Planar segmentation
  		pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
  		pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
  		pcl::SACSegmentation<pcl::PointXYZRGB> seg;
 		seg.setOptimizeCoefficients (true);
  		seg.setModelType (pcl::SACMODEL_PLANE);
  		seg.setMethodType (pcl::SAC_RANSAC);
  		seg.setDistanceThreshold (0.01);
  		seg.setInputCloud (input);
  		seg.segment (*inliers, *coefficients);
  		if (inliers->indices.size () == 0)
    			PCL_ERROR ("Could not estimate a planar model for the given dataset.");

    		pcl::IndicesPtr indices (new vector <int>);
    		pcl::PassThrough<pcl::PointXYZRGB> pass;
    		pass.setInputCloud (input);
    		pass.setFilterFieldName ("z");
    		pass.setFilterLimits (0.0, 2.0);
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

//Region growing segmentation
		if(regionGrowingSeg){
			pcl::search::Search<pcl::PointXYZRGB>::Ptr tree = 
			boost::shared_ptr<pcl::search::Search<pcl::PointXYZRGB> > 
			(new pcl::search::KdTree<pcl::PointXYZRGB>);
  			pcl::PointCloud <pcl::Normal>::Ptr normals (new pcl::PointCloud <pcl::Normal>);
  			pcl::NormalEstimation<pcl::PointXYZRGB, pcl::Normal> normal_estimator;
  			normal_estimator.setSearchMethod (tree);
  			normal_estimator.setInputCloud (input);
  			normal_estimator.setKSearch (150);
  			normal_estimator.compute (*normals);

  			pcl::RegionGrowing<pcl::PointXYZRGB, pcl::Normal> reg;
  			reg.setMinClusterSize (100);
  			reg.setMaxClusterSize (1000000);
  			reg.setSearchMethod (tree);
  			reg.setNumberOfNeighbours (10);
  			reg.setInputCloud (input);
			reg.setIndices(segmentedIndices);
  			reg.setInputNormals (normals);
  			reg.setSmoothnessThreshold (3.0 / 180.0 * M_PI);
  			reg.setCurvatureThreshold (1.0);
    			vector <pcl::PointIndices> clusters;
    			reg.extract (clusters);
    			cloud = *(reg.getColoredCloud ());
		}

//Region growing RGB segmentation
		if(regionRGBSeg){
			pcl::search::Search <pcl::PointXYZRGB>::Ptr tree = 
			boost::shared_ptr<pcl::search::Search<pcl::PointXYZRGB> > 
			(new pcl::search::KdTree<pcl::PointXYZRGB>);
    			pcl::RegionGrowingRGB<pcl::PointXYZRGB> reg;
    			reg.setInputCloud (input);
    			reg.setIndices (segmentedIndices);
    			reg.setSearchMethod (tree);
    			reg.setDistanceThreshold (10);
    			reg.setPointColorThreshold (75);
    			reg.setRegionColorThreshold (5);
    			reg.setMinClusterSize (400);
    			vector <pcl::PointIndices> clusters;
    			reg.extract (clusters);
    			cloud = *(reg.getColoredCloud ());
		}
	
		cloudCBCalled = true;
	}
}

//detections_cb gets regions of interest from /object_detection/detections (a custom message that uses 
//sensor_msgs/Image data) and publishes PointCloud data of the detected objects based on the segmented regions
//in those areas
void detections_cb(const cob_perception_msgs::DetectionArray::ConstPtr& input){
	if(cloudCBCalled){	
		pclCloud output;
		output.header.frame_id = input->header.frame_id;
		for(int i = 0; i < input->detections.size(); i++){
			cob_perception_msgs::Rect roi = input->detections[i].mask.roi;
       			set<int> colorSet;
       			vector<int> colorVector;
			//planar segmentation sets filtered regions to red
       			const int filteredColor = 16711680;
       			for (int x = roi.x; x < roi.x + roi.width; x++)
           			for (int y = roi.y; y < roi.y + roi.height; y++)
               				if (cloud.at(x, y).rgba != filteredColor) 
					{
                   				colorSet.insert(cloud.at(x, y).rgba);
                   				colorVector.push_back(cloud.at(x, y).rgba);
               				}
       			int mostCommonColor;
       			int mostOccurrences = 0;
       			for (set<int>::iterator it = colorSet.begin(); it != colorSet.end(); it++) {
           			int c = count(colorVector.begin(), colorVector.end(), *it);
           			if (c > mostOccurrences) {
               				mostOccurrences = c;
               				mostCommonColor = *it;
          			}
       			}
			//sets largest non-planar region in roi to output
       			for (int x = roi.x; x < roi.x + roi.width; x++)
           			for (int y = roi.y; y < roi.y + roi.height; y++)
               			if (mostCommonColor == cloud.at(x, y).rgba)
                   				output.push_back(cloud.at(x, y));
			cout << input->detections[i].label << "\n";
		}
   		pub.publish(output);
	}
}



int main (int argc, char** argv){
  ros::init(argc, argv, "object_cloud");
  ros::NodeHandle n;
  //regionGrowingSeg = true;
  regionRGBSeg = true;
  ros::Subscriber pcl_sub = n.subscribe("/camera/depth_registered/points", 1, pcl_cb);
  //ros::Subscriber pcl_sub = n.subscribe("/VoxelGrid", 1, pcl_cb);
  ros::Subscriber detection_sub = n.subscribe("/object_detection/detections", 1, detections_cb);
  pub = n.advertise<sensor_msgs::PointCloud2>("/object_cloud", 1);
  ros::spin();

  return (0);
}
