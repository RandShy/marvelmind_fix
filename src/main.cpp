#include <ros/ros.h>
#include <marvelmind_nav/hedge_pos.h>

ros::Publisher pub;

void callback(const marvelmind_nav::hedge_pos& msg)
{
    marvelmind_nav::hedge_pos correctedMsg = msg;
    correctedMsg.z_m = 0.0;
    pub.publish(correctedMsg);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "marvelmind_fix_node");
    ros::NodeHandle nh;
    
    ros::Subscriber sub = nh.subscribe("hedge_pos", 1000, callback);
    pub = nh.advertise<marvelmind_nav::hedge_pos>("hedge_pos_corrected", 1000);

    ros::spin();

    return 0;
}

