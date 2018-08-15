// Generated by gencpp from file cob_3d_mapping_msgs/SetBoundingBoxesResponse.msg
// DO NOT EDIT!


#ifndef COB_3D_MAPPING_MSGS_MESSAGE_SETBOUNDINGBOXESRESPONSE_H
#define COB_3D_MAPPING_MSGS_MESSAGE_SETBOUNDINGBOXESRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace cob_3d_mapping_msgs
{
template <class ContainerAllocator>
struct SetBoundingBoxesResponse_
{
  typedef SetBoundingBoxesResponse_<ContainerAllocator> Type;

  SetBoundingBoxesResponse_()
    {
    }
  SetBoundingBoxesResponse_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }






  typedef boost::shared_ptr< ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SetBoundingBoxesResponse_

typedef ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<std::allocator<void> > SetBoundingBoxesResponse;

typedef boost::shared_ptr< ::cob_3d_mapping_msgs::SetBoundingBoxesResponse > SetBoundingBoxesResponsePtr;
typedef boost::shared_ptr< ::cob_3d_mapping_msgs::SetBoundingBoxesResponse const> SetBoundingBoxesResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace cob_3d_mapping_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'cob_object_detection_msgs': ['/home/dan/dan_ws/devel/.private/cob_object_detection_msgs/share/cob_object_detection_msgs/msg', '/home/dan/dan_ws/src/cob_perception_common/cob_object_detection_msgs/msg'], 'cob_3d_mapping_msgs': ['/home/dan/dan_ws/devel/.private/cob_3d_mapping_msgs/share/cob_3d_mapping_msgs/msg', '/home/dan/dan_ws/src/cob_perception_common/cob_3d_mapping_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cob_3d_mapping_msgs/SetBoundingBoxesResponse";
  }

  static const char* value(const ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
";
  }

  static const char* value(const ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetBoundingBoxesResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::cob_3d_mapping_msgs::SetBoundingBoxesResponse_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // COB_3D_MAPPING_MSGS_MESSAGE_SETBOUNDINGBOXESRESPONSE_H
