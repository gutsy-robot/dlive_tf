#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "car_tf_publisher");
  ros::NodeHandle n;

  ros::Rate r(100);

  tf::TransformBroadcaster base_zed_broadcaster;
  tf::TransformBroadcaster base_sensors_broadcaster;

  while(n.ok()){
    base_zed_broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(-1.0, 0.0, 1.5)),
        ros::Time::now(),"base_link", "zed_initial_link"));
    base_sensors_broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(-2.5, 0.0, 1.8)),
        ros::Time::now(),"base_link", "sensors_link"));
    r.sleep();
  }
}
