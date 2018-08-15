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
  ros::Subscriber sub = n.subscribe("/camera/depth_registered/points", 1000, cloud_cb);
  pub = n.advertise<sensor_msgs::PointCloud2>("/kinect_segmentation", 1000);
  ros::spin();

  return (0);
}
