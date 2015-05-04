#ifndef _ROS_control_msgs_GripperCommand_h
#define _ROS_control_msgs_GripperCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace control_msgs
{

  class GripperCommand : public ros::Msg
  {
    public:
      float position;
      float max_effort;

    GripperCommand():
      position(0),
      max_effort(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_SERIALIZE
      offset += serializeAvrFloat64(outbuffer + offset, this->position);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_effort);
#endif
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_DESERIALIZE
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_effort));
#endif
     return offset;
    }

    const char * getType(){ return "control_msgs/GripperCommand"; };
    const char * getMD5(){ return "680acaff79486f017132a7f198d40f08"; };

  };

}
#endif