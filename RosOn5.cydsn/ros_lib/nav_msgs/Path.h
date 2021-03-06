#ifndef _ROS_nav_msgs_Path_h
#define _ROS_nav_msgs_Path_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PoseStamped.h"

namespace nav_msgs
{

  class Path : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t poses_length;
      geometry_msgs::PoseStamped st_poses;
      geometry_msgs::PoseStamped * poses;

    Path():
      header(),
      poses_length(0), poses(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_SERIALIZE
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = poses_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < poses_length; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
#endif
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_DESERIALIZE
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t poses_lengthT = *(inbuffer + offset++);
      if(poses_lengthT < poses_length)
        poses_length = poses_lengthT;
      offset += 3;
      for( uint8_t i = 0; i < poses_lengthT; i++){
      offset += this->st_poses.deserialize(inbuffer + offset);
      if (i < poses_length) {
          memcpy( &(this->poses[i]), &(this->st_poses), sizeof(geometry_msgs::PoseStamped));
      }
      }
#endif
     return offset;
    }

    const char * getType(){ return "nav_msgs/Path"; };
    const char * getMD5(){ return "6227e2b7e9cce15051f669a5e197bbf7"; };

  };

}
#endif