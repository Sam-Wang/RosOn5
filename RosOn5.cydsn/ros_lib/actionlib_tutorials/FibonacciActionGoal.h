#ifndef _ROS_actionlib_tutorials_FibonacciActionGoal_h
#define _ROS_actionlib_tutorials_FibonacciActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "actionlib_tutorials/FibonacciGoal.h"

namespace actionlib_tutorials
{

  class FibonacciActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      actionlib_tutorials::FibonacciGoal goal;

    FibonacciActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_SERIALIZE
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
#endif
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
#ifndef ROS_MSG_DONT_DESERIALIZE
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
#endif
     return offset;
    }

    const char * getType(){ return "actionlib_tutorials/FibonacciActionGoal"; };
    const char * getMD5(){ return "006871c7fa1d0e3d5fe2226bf17b2a94"; };

  };

}
#endif