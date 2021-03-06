// Generated by gencpp from file cob_object_detection_msgs/Rect.msg
// DO NOT EDIT!


#ifndef COB_OBJECT_DETECTION_MSGS_MESSAGE_RECT_H
#define COB_OBJECT_DETECTION_MSGS_MESSAGE_RECT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace cob_object_detection_msgs
{
template <class ContainerAllocator>
struct Rect_
{
  typedef Rect_<ContainerAllocator> Type;

  Rect_()
    : x(0)
    , y(0)
    , width(0)
    , height(0)  {
    }
  Rect_(const ContainerAllocator& _alloc)
    : x(0)
    , y(0)
    , width(0)
    , height(0)  {
  (void)_alloc;
    }



   typedef int32_t _x_type;
  _x_type x;

   typedef int32_t _y_type;
  _y_type y;

   typedef int32_t _width_type;
  _width_type width;

   typedef int32_t _height_type;
  _height_type height;




  typedef boost::shared_ptr< ::cob_object_detection_msgs::Rect_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cob_object_detection_msgs::Rect_<ContainerAllocator> const> ConstPtr;

}; // struct Rect_

typedef ::cob_object_detection_msgs::Rect_<std::allocator<void> > Rect;

typedef boost::shared_ptr< ::cob_object_detection_msgs::Rect > RectPtr;
typedef boost::shared_ptr< ::cob_object_detection_msgs::Rect const> RectConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cob_object_detection_msgs::Rect_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cob_object_detection_msgs::Rect_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace cob_object_detection_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'cob_object_detection_msgs': ['/home/dan/dan_ws/devel/.private/cob_object_detection_msgs/share/cob_object_detection_msgs/msg', '/home/dan/dan_ws/src/cob_perception_common/cob_object_detection_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::cob_object_detection_msgs::Rect_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cob_object_detection_msgs::Rect_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_object_detection_msgs::Rect_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_object_detection_msgs::Rect_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_object_detection_msgs::Rect_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_object_detection_msgs::Rect_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cob_object_detection_msgs::Rect_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4425f1067abc7ec2e487d28194eccff4";
  }

  static const char* value(const ::cob_object_detection_msgs::Rect_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4425f1067abc7ec2ULL;
  static const uint64_t static_value2 = 0xe487d28194eccff4ULL;
};

template<class ContainerAllocator>
struct DataType< ::cob_object_detection_msgs::Rect_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cob_object_detection_msgs/Rect";
  }

  static const char* value(const ::cob_object_detection_msgs::Rect_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cob_object_detection_msgs::Rect_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 x\n\
int32 y\n\
int32 width\n\
int32 height\n\
";
  }

  static const char* value(const ::cob_object_detection_msgs::Rect_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cob_object_detection_msgs::Rect_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.width);
      stream.next(m.height);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Rect_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cob_object_detection_msgs::Rect_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cob_object_detection_msgs::Rect_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<int32_t>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<int32_t>::stream(s, indent + "  ", v.y);
    s << indent << "width: ";
    Printer<int32_t>::stream(s, indent + "  ", v.width);
    s << indent << "height: ";
    Printer<int32_t>::stream(s, indent + "  ", v.height);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COB_OBJECT_DETECTION_MSGS_MESSAGE_RECT_H
