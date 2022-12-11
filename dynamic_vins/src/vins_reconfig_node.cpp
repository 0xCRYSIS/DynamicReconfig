#include <ros/ros.h>

#include <dynamic_reconfigure/server.h>
// #include <dynamic_vins/VinsConfig.h>
#include <dynamic_vins/dynamicConfig.h>

void callback(dynamic_vins::dynamicConfig &config, uint32_t level)
{
    ROS_INFO("Reconfigure Request : %d %f %s %s",
            config.int_param,config.double_param,
            config.str_param.c_str(),
            config.bool_param?"True":"False");
}


int main(int argc , char **argv)
{
    ros::init(argc,argv,"vins_reconfig");

    dynamic_reconfigure::Server<dynamic_vins::dynamicConfig> server;
    dynamic_reconfigure::Server<dynamic_vins::dynamicConfig>::CallbackType f;

    f = boost::bind(&callback,_1,_2);
    server.setCallback(f);

    ROS_INFO("Spinning node");
    ros::spin();
    return 0;
}