// Generated by gencpp from file cob_3d_mapping_msgs/Point2D.msg
// DO NOT EDIT!


#ifndef COB_3D_MAPPING_MSGS_MESSAGE_POINT2D_H
#define COB_3D_MAPPING_MSGS_MESSAGE_POINT2D_H


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
struct Point2D_
{
  typedef Point2D_<ContainerAllocator> Type;

  Point2D_()
    : x(0.0)
    , y(0.0)
    , tex_x(0.0)
    , tex_y(0.0)
    , var(0.0)  {
    }
  Point2D_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , tex_x(0.0)
    , tex_y(0.0)
    , var(0.0)  {
  (void)_alloc;
    }



   typedef float _x_type;
  _x_type x;

   typedef float _y_type;
  _y_type y;

   typedef float _tex_x_type;
  _tex_x_type tex_x;

   typedef float _tex_y_type;
  _tex_y_type tex_y;

   typedef float _var_type;
  _var_type var;




  typedef boost::shared_ptr< ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator> const> ConstPtr;

}; // struct Point2D_

typedef ::cob_3d_mapping_msgs::Point2D_<std::allocator<void> > Point2D;

typedef boost::shared_ptr< ::cob_3d_mapping_msgs::Point2D > Point2DPtr;
typedef boost::shared_ptr< ::cob_3d_mapping_msgs::Point2D const> Point2DConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fc725bda50adf2bf28e55ed21147f45e";
  }

  static const char* value(const ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xfc725bda50adf2bfULL;
  static const uint64_t static_value2 = 0x28e55ed21147f45eULL;
};

template<class ContainerAllocator>
struct DataType< ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cob_3d_mapping_msgs/Point2D";
  }

  static const char* value(const ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#coordinate on surface\n\
float32 x\n\
float32 y\n\
\n\
#texture cooridante\n\
float32 tex_x\n\
float32 tex_y\n\
\n\
float32 var\n\
";
  }

  static const char* value(const ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.tex_x);
      stream.next(m.tex_y);
      stream.next(m.var);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Point2D_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cob_3d_mapping_msgs::Point2D_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<float>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<float>::stream(s, indent + "  ", v.y);
    s << indent << "tex_x: ";
    Printer<float>::stream(s, indent + "  ", v.tex_x);
    s << indent << "tex_y: ";
    Printer<float>::stream(s, indent + "  ", v.tex_y);
    s << indent << "var: ";
    Printer<float>::stream(s, indent + "  ", v.var);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COB_3D_MAPPING_MSGS_MESSAGE_POINT2D_H
