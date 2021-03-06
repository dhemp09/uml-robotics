// Generated by gencpp from file cob_3d_mapping_msgs/GetBoundingBoxes.msg
// DO NOT EDIT!


#ifndef COB_3D_MAPPING_MSGS_MESSAGE_GETBOUNDINGBOXES_H
#define COB_3D_MAPPING_MSGS_MESSAGE_GETBOUNDINGBOXES_H

#include <ros/service_traits.h>


#include <cob_3d_mapping_msgs/GetBoundingBoxesRequest.h>
#include <cob_3d_mapping_msgs/GetBoundingBoxesResponse.h>


namespace cob_3d_mapping_msgs
{

struct GetBoundingBoxes
{

typedef GetBoundingBoxesRequest Request;
typedef GetBoundingBoxesResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetBoundingBoxes
} // namespace cob_3d_mapping_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::cob_3d_mapping_msgs::GetBoundingBoxes > {
  static const char* value()
  {
    return "2c8e5a484f41a0aac9855792591d7d4c";
  }

  static const char* value(const ::cob_3d_mapping_msgs::GetBoundingBoxes&) { return value(); }
};

template<>
struct DataType< ::cob_3d_mapping_msgs::GetBoundingBoxes > {
  static const char* value()
  {
    return "cob_3d_mapping_msgs/GetBoundingBoxes";
  }

  static const char* value(const ::cob_3d_mapping_msgs::GetBoundingBoxes&) { return value(); }
};


// service_traits::MD5Sum< ::cob_3d_mapping_msgs::GetBoundingBoxesRequest> should match 
// service_traits::MD5Sum< ::cob_3d_mapping_msgs::GetBoundingBoxes > 
template<>
struct MD5Sum< ::cob_3d_mapping_msgs::GetBoundingBoxesRequest>
{
  static const char* value()
  {
    return MD5Sum< ::cob_3d_mapping_msgs::GetBoundingBoxes >::value();
  }
  static const char* value(const ::cob_3d_mapping_msgs::GetBoundingBoxesRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::cob_3d_mapping_msgs::GetBoundingBoxesRequest> should match 
// service_traits::DataType< ::cob_3d_mapping_msgs::GetBoundingBoxes > 
template<>
struct DataType< ::cob_3d_mapping_msgs::GetBoundingBoxesRequest>
{
  static const char* value()
  {
    return DataType< ::cob_3d_mapping_msgs::GetBoundingBoxes >::value();
  }
  static const char* value(const ::cob_3d_mapping_msgs::GetBoundingBoxesRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::cob_3d_mapping_msgs::GetBoundingBoxesResponse> should match 
// service_traits::MD5Sum< ::cob_3d_mapping_msgs::GetBoundingBoxes > 
template<>
struct MD5Sum< ::cob_3d_mapping_msgs::GetBoundingBoxesResponse>
{
  static const char* value()
  {
    return MD5Sum< ::cob_3d_mapping_msgs::GetBoundingBoxes >::value();
  }
  static const char* value(const ::cob_3d_mapping_msgs::GetBoundingBoxesResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::cob_3d_mapping_msgs::GetBoundingBoxesResponse> should match 
// service_traits::DataType< ::cob_3d_mapping_msgs::GetBoundingBoxes > 
template<>
struct DataType< ::cob_3d_mapping_msgs::GetBoundingBoxesResponse>
{
  static const char* value()
  {
    return DataType< ::cob_3d_mapping_msgs::GetBoundingBoxes >::value();
  }
  static const char* value(const ::cob_3d_mapping_msgs::GetBoundingBoxesResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // COB_3D_MAPPING_MSGS_MESSAGE_GETBOUNDINGBOXES_H
