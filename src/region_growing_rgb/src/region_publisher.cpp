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

ros::Publisher pub;
tf::TransformListener* tfListener;

void cloud_cb(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr input){ 

//PointCloud2 to PointCloud<pcl::PointXYZRGB> (unnecessary)
//void cloud_cb(const boost::shared_ptr<const sensor_msgs::PointCloud2>& input){  
   // pcl::PCLPointCloud2 pcl_pc2;
   // pcl_conversions::toPCL(*input, pcl_pc2);
   // pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    //pcl::fromPCLPointCloud2(pcl_pc2,*cloud);

    //transform PCL data orientation to world frame
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr tfCloud (new pcl::PointCloud<pcl::PointXYZRGB>);	
    //tfListener->waitForTransform("world", input->header.frame_id, ros::Time(1), ros::Duration(5.0));
    pcl_ros::transformPointCloud("/world", *input, *tfCloud, *tfListener);
    //pcl_ros::transformPointCloud("/world", *cloud, *tfCloud, *tfListener);

    //Region Growing RGB implementation
    pcl::search::Search <pcl::PointXYZRGB>::Ptr tree =
    boost::shared_ptr<pcl::search::Search<pcl::PointXYZRGB> > (new pcl::search::KdTree<pcl::PointXYZRGB>);
    pcl::IndicesPtr indices (new std::vector <int>);
    pcl::PassThrough<pcl::PointXYZRGB> pass;
    pass.setInputCloud (input);
    //pass.setInputCloud (cloud);
    pass.setFilterFieldName ("z");
    pass.setFilterLimits (0.0, 4.0);

    pass.filter (*indices);

    pcl::RegionGrowingRGB<pcl::PointXYZRGB> reg;
    reg.setInputCloud (input);
    //reg.setInputCloud (cloud);
    reg.setIndices (indices);
    reg.setSearchMethod (tree);
    reg.setDistanceThreshold (10);
    reg.setPointColorThreshold (6);
    reg.setRegionColorThreshold (5);
    reg.setMinClusterSize (400);

    std::vector <pcl::PointIndices> clusters;
    reg.extract (clusters);

    pcl::PointCloud <pcl::PointXYZRGB>::Ptr colored_cloud = reg.getColoredCloud ();

    //output region data as sensor_msgs::PointCloud2
    sensor_msgs::PointCloud2 output;
    pcl::toROSMsg(*colored_cloud, output);
    output.header.frame_id = input->header.frame_id;
    pub.publish(output);   
    
}

int main (int argc, char** argv)
{
  ros::init(argc, argv, "pclDataSubscriber");
  ros::NodeHandle n;
  tfListener = new tf::TransformListener();
  ros::Subscriber sub = n.subscribe("/multisense/image_points2_color", 1000, cloud_cb);
  pub = n.advertise<sensor_msgs::PointCloud2>("/region_grow", 1000);
  ros::spin();

  return (0);
}
