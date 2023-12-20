/***********************************************************************
Copyright 2020 GuYueHome (www.guyuehome.com).
***********************************************************************/

/**
 * 该例程将请求/spawn服务，服务数据类型turtlesim::Spawn
 */

#include <ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc, char** argv)
{
    // 初始化ROS节点
	ros::init(argc, argv, "turtle_spawn");

    // 创建节点句柄
	ros::NodeHandle node;

    // 发现/spawn服务后，创建一个服务客户端，连接名为/spawn的service
	ros::service::waitForService("/spawn");
	ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("/spawn");

    // 初始化turtlesim::Spawn的请求数据
	turtlesim::Spawn srv;
	srv.request.x = 2.0;
	srv.request.y = 2.0;
	srv.request.name = "turtle2";

	turtlesim::Spawn srv1;
	srv1.request.x = 3.0;
	srv1.request.y = 3.0;
	srv1.request.name = "turtle3";

	turtlesim::Spawn srv2;
	srv2.request.x = 4.0;
	srv2.request.y = 4.0;
	srv2.request.name = "turtle4";

    // 请求服务调用
	ROS_INFO("Call service to spwan turtle[x:%0.6f, y:%0.6f, name:%s]", 
			 srv.request.x, srv.request.y, srv.request.name.c_str());
	add_turtle.call(srv);

	ROS_INFO("Call service to spwan turtle[x:%0.6f, y:%0.6f, name:%s]", 
			 srv1.request.x, srv1.request.y, srv1.request.name.c_str());
	add_turtle.call(srv1);

	ROS_INFO("Call service to spwan turtle[x:%0.6f, y:%0.6f, name:%s]", 
			 srv2.request.x, srv2.request.y, srv2.request.name.c_str());
	add_turtle.call(srv2);

	// 显示服务调用结果
	ROS_INFO("Spwan turtle successfully [name:%s]", srv.response.name.c_str());

	ROS_INFO("Spwan turtle successfully [name:%s]", srv1.response.name.c_str());

	ROS_INFO("Spwan turtle successfully [name:%s]", srv2.response.name.c_str());

	return 0;
};
