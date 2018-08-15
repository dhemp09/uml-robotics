// Generated by gencpp from file cob_3d_mapping_msgs/UpdateMap.msg
// DO NOT EDIT!


#ifndef COB_3D_MAPPING_MSGS_MESSAGE_UPDATEMAP_H
#define COB_3D_MAPPING_MSGS_MESSAGE_UPDATEMAP_H

#include <ros/service_traits.h>


#include <cob_3d_mapping_msgs/UpdateMapRequest.h>
#include <cob_3d_mapping_msgs/UpdateMapResponse.h>


namespace cob_3d_mapping_msgs
{

struct UpdateMap
{

typedef UpdateMapRequest Request;
typedef UpdateMapResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct UpdateMap
} // namespace cob_3d_mapping_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::cob_3d_mapping_msgs::UpdateMap > {
  static const char* value()
  {
    return "ab790ffed241af3217fe4286cc1c1989";
  }

  static const char* value(const ::cob_3d_mapping_msgs::UpdateMap&) { return value(); }
};

template<>
struct DataType< ::cob_3d_mapping_msgs::UpdateMap > {
  static const char* value()
  {
    return "cob_3d_mapping_msgs/UpdateMap";
  }

  static const char* value(const ::cob_3d_mapping_msgs::UpdateMap&) { return value(); }
};


// service_traits::MD5Sum< ::cob_3d_mapping_msgs::UpdateMapRequest> should match 
// service_traits::MD5Sum< ::cob_3d_mapping_msgs::UpdateMap > 
template<>
struct MD5Sum< ::cob_3d_mapping_msgs::UpdateMapRequest>
{
  static const char* value()
  {
    return MD5Sum< ::cob_3d_mapping_msgs::UpdateMap >::value();
  }
  static const char* value(const ::cob_3d_mapping_msgs::UpdateMapRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::cob_3d_mapping_msgs::UpdateMapRequest> should match 
// service_traits::DataType< ::cob_3d_mapping_msgs::UpdateMap > 
template<>
struct DataType< ::cob_3d_mapping_msgs::UpdateMapRequest>
{
  static const char* value()
  {
    return DataType< ::cob_3d_mapping_msgs::UpdateMap >::value();
  }
  static const char* value(const ::cob_3d_mapping_msgs::UpdateMapRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::cob_3d_mapping_msgs::UpdateMapResponse> should match 
// service_traits::MD5Sum< ::cob_3d_mapping_msgs::UpdateMap > 
template<>
struct MD5Sum< ::cob_3d_mapping_msgs::UpdateMapResponse>
{
  static const char* value()
  {
    return MD5Sum< ::cob_3d_mapping_msgs::UpdateMap >::value();
  }
  static const char* value(const ::cob_3d_mapping_msgs::UpdateMapResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::cob_3d_mapping_msgs::UpdateMapResponse> should match 
// service_traits::DataType< ::cob_3d_mapping_msgs::UpdateMap > 
template<>
struct DataType< ::cob_3d_mapping_msgs::UpdateMapResponse>
{
  static const char* value()
  {
    return DataType< ::cob_3d_mapping_msgs::UpdateMap >::value();
  }
  static const char* value(const ::cob_3d_mapping_msgs::UpdateMapResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // COB_3D_MAPPING_MSGS_MESSAGE_UPDATEMAP_H