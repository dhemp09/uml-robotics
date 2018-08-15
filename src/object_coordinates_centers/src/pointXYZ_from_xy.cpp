#include<ros/ros.h>
#include<pcl/PCLPointCloud2.h>
#include<pcl/conversions.h>
#include<geometry_msgs/PoseArray.h>
#include<pcl/point_types.h>
#include<pcl/io/pcd_io.h>
#include<pcl_ros/transforms.h>
#include<vector>
#include<pcl_ros/point_cloud.h>
#include <visualization_msgs/Marker.h>

ros::Publisher pub;
ros::Publisher marker;
pcl::PointCloud<pcl::PointXYZRGB> m;

void callBack(const geometry_msgs::PoseArray::ConstPtr& msg){
	
	pcl::PointCloud<pcl::PointXYZRGB> centers;
	centers.header.frame_id = msg->header.frame_id;
	for(int i = 0; i < msg->poses.size(); i++){
		centers.push_back(m.at(msg->poses[i].position.x, msg->poses[i].position.y));
		std::cerr << centers.points[i].rgba << std::endl;
	}

	
	for(int i = 0; i < centers.size(); i++){
		visualization_msgs::Marker mark;
		mark.header.frame_id = centers.header.frame_id;
		mark.header.stamp = ros::Time::now();
		mark.ns = "table";
        	mark.id = i;
		mark.type = mark.CUBE;
        	mark.action = visualization_msgs::Marker::ADD;
		mark.pose.position.x = centers.points[i].x;
        	mark.pose.position.y = centers.points[i].y; 
        	mark.pose.position.z = centers.points[i].z;  
       		mark.pose.orientation.x = 0.0;
        	mark.pose.orientation.y = 0.0;
        	mark.pose.orientation.z = 0.0;
        	mark.pose.orientation.w = 1.0;
        
        	double size = .04;
        	mark.scale.x = size;
        	mark.scale.y = size;
        	mark.scale.z = size;
        
        	mark.color.r = 0.0f;
        	mark.color.g = 0.0f;
        	mark.color.b = 1.0f;
        	mark.color.a = 1.0;
        
        	mark.lifetime = ros::Duration(4.0);
		marker.publish(mark);
	}
	pub.publish(centers);
}

int main (int argc, char** argv){
	ros::init(argc, argv, "pointXYZCoordinate");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("/object_centers", 1, callBack);
	m = *(ros::topic::waitForMessage<pcl::PointCloud<pcl::PointXYZRGB> >
		("/camera/depth_registered/points", n));	
	pub = n.advertise<pcl::PointCloud<pcl::PointXYZRGB> >("/object_XYZ_centers", 1);
	marker = n.advertise<visualization_msgs::Marker>("/object_center_markers", 1);
	ros::spin();

	return 0;
}
