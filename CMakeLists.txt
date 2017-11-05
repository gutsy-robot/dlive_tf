cmake_minimum_required(VERSION 2.8.3)
project(dlive_tf)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  tf
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES dlive_tf
#  CATKIN_DEPENDS geometry_msgs roscpp rospy tf
#  DEPENDS system_lib
)
include_directories(include ${catkin_INCLUDE_DIRS})

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
add_executable(${PROJECT_NAME}_node src/tf_broadcast.cpp)
target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})
