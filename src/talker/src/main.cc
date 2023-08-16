
#include "ros/ros.h"
#include "proto/message.pb.h"
#include "my_message_trait.h"
#include "std_msgs/String.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "protobuf_publisher");
    ros::NodeHandle nh;

    ros::Publisher pub;
    
    pub = nh.advertise<test::ShortMessage>("protobuf_topic", 10);

    test::ShortMessage mymessage;
    mymessage.set_content("abc");

    ros::Rate loop_rate(10);  // 10 Hz

    while (ros::ok()) {

        std::string serialized_msg;
        mymessage.SerializeToString(&serialized_msg);

        pub.publish(mymessage);

        ROS_INFO("10");

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
