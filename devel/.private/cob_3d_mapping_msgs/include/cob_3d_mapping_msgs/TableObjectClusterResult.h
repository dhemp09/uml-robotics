// Generated by gencpp from file cob_3d_mapping_msgs/TableObjectClusterResult.msg
// DO NOT EDIT!


#ifndef COB_3D_MAPPING_MSGS_MESSAGE_TABLEOBJECTCLUSTERRESULT_H
#define COB_3D_MAPPING_MSGS_MESSAGE_TABLEOBJECTCLUSTERRESULT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <cob_object_detection_msgs/DetectionArray.h>

namespace cob_3d_mapping_msgs
{
template <class ContainerAllocator>
struct TableObjectClusterResult_
{
  typedef TableObjectClusterResult_<ContainerAllocator> Type;

  TableObjectClusterResult_()
    : bounding_boxes()  {
    }
  TableObjectClusterResult_(const ContainerAllocator& _alloc)
    : bounding_boxes(_alloc)  {
  (void)_alloc;
    }



   typedef  ::cob_object_detection_msgs::DetectionArray_<ContainerAllocator>  _bounding_boxes_type;
  _bounding_boxes_type bounding_boxes;




  typedef boost::shared_ptr< ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator> const> ConstPtr;

}; // struct TableObjectClusterResult_

typedef ::cob_3d_mapping_msgs::TableObjectClusterResult_<std::allocator<void> > TableObjectClusterResult;

typedef boost::shared_ptr< ::cob_3d_mapping_msgs::TableObjectClusterResult > TableObjectClusterResultPtr;
typedef boost::shared_ptr< ::cob_3d_mapping_msgs::TableObjectClusterResult const> TableObjectClusterResultConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace cob_3d_mapping_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'cob_object_detection_msgs': ['/home/dan/dan_ws/devel/.private/cob_object_detection_msgs/share/cob_object_detection_msgs/msg', '/home/dan/dan_ws/src/cob_perception_common/cob_object_detection_msgs/msg'], 'cob_3d_mapping_msgs': ['/home/dan/dan_ws/devel/.private/cob_3d_mapping_msgs/share/cob_3d_mapping_msgs/msg', '/home/dan/dan_ws/src/cob_perception_common/cob_3d_mapping_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "de59b28161e64013a1dd6ca094ca3cc7";
  }

  static const char* value(const ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xde59b28161e64013ULL;
  static const uint64_t static_value2 = 0xa1dd6ca094ca3cc7ULL;
};

template<class ContainerAllocator>
struct DataType< ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cob_3d_mapping_msgs/TableObjectClusterResult";
  }

  static const char* value(const ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#result definition\n\
cob_object_detection_msgs/DetectionArray bounding_boxes\n\
\n\
================================================================================\n\
MSG: cob_object_detection_msgs/DetectionArray\n\
Header header\n\
Detection[] detections\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: cob_object_detection_msgs/Detection\n\
Header header\n\
string label\n\
int32 id\n\
string detector\n\
float32 score\n\
Mask mask\n\
geometry_msgs/PoseStamped pose\n\
geometry_msgs/Point bounding_box_lwh\n\
\n\
================================================================================\n\
MSG: cob_object_detection_msgs/Mask\n\
# this message is used to mark where an object is present in an image\n\
# this can be done either by a roi region on the image (less precise) or a mask (more precise)\n\
\n\
Rect roi\n\
\n\
# in the case when mask is used, 'roi' specifies the image region and 'mask'\n\
# (which should be of the same size) a binary mask in that region\n\
sensor_msgs/Image mask\n\
\n\
# in the case there is 3D data available, 'indices' are used to index the \n\
# part of the point cloud representing the object\n\
#pcl/PointIndices indices\n\
\n\
================================================================================\n\
MSG: cob_object_detection_msgs/Rect\n\
int32 x\n\
int32 y\n\
int32 width\n\
int32 height\n\
\n\
================================================================================\n\
MSG: sensor_msgs/Image\n\
# This message contains an uncompressed image\n\
# (0, 0) is at top-left corner of image\n\
#\n\
\n\
Header header        # Header timestamp should be acquisition time of image\n\
                     # Header frame_id should be optical frame of camera\n\
                     # origin of frame should be optical center of cameara\n\
                     # +x should point to the right in the image\n\
                     # +y should point down in the image\n\
                     # +z should point into to plane of the image\n\
                     # If the frame_id here and the frame_id of the CameraInfo\n\
                     # message associated with the image conflict\n\
                     # the behavior is undefined\n\
\n\
uint32 height         # image height, that is, number of rows\n\
uint32 width          # image width, that is, number of columns\n\
\n\
# The legal values for encoding are in file src/image_encodings.cpp\n\
# If you want to standardize a new string format, join\n\
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.\n\
\n\
string encoding       # Encoding of pixels -- channel meaning, ordering, size\n\
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h\n\
\n\
uint8 is_bigendian    # is this data bigendian?\n\
uint32 step           # Full row length in bytes\n\
uint8[] data          # actual matrix data, size is (step * rows)\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseStamped\n\
# A Pose with reference coordinate frame and timestamp\n\
Header header\n\
Pose pose\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
  }

  static const char* value(const ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.bounding_boxes);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TableObjectClusterResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cob_3d_mapping_msgs::TableObjectClusterResult_<ContainerAllocator>& v)
  {
    s << indent << "bounding_boxes: ";
    s << std::endl;
    Printer< ::cob_object_detection_msgs::DetectionArray_<ContainerAllocator> >::stream(s, indent + "  ", v.bounding_boxes);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COB_3D_MAPPING_MSGS_MESSAGE_TABLEOBJECTCLUSTERRESULT_H
