#include <ros/ros.h>
#include <cob_perception_msgs/DetectionArray.h>
#include <cob_perception_msgs/Detection.h>
#include <cob_perception_msgs/Rect.h>
#include <cob_perception_msgs/Mask.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseArray.h>
#include <vector>

using namespace std;
using namespace ros;

Publisher pub;

void callBack(const cob_perception_msgs::DetectionArray::ConstPtr& msg){
	geometry_msgs::PoseArray pos;
	pos.header.frame_id = msg->header.frame_id;
	if(!msg->detections.empty())
		for(int i = 0; i < msg->detections.size(); i++){
			geometry_msgs::Pose point;
			point.position.x = msg->detections[i].mask.roi.x + (msg->detections[i].mask.roi.width / 2);
			point.position.y = msg->detections[i].mask.roi.y + (msg->detections[i].mask.roi.height / 2)				;
			pos.poses.push_back(point);
		}	
	pub.publish(pos);			
       
}
int main(int argc, char** argv){
	init(argc, argv, "object_detection_subscriber");
	NodeHandle n;
	Subscriber sub = n.subscribe("/object_detection/detections", 1, callBack);
	pub = n.advertise<geometry_msgs::PoseArray>("/object_centers", 1);
	while(ok())
		spinOnce();
	return 0;
}
