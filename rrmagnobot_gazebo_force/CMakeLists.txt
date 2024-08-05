cmake_minimum_required(VERSION 3.5.0)
project(rrmagnobot_gazebo_force)

find_package(ament_cmake REQUIRED)
find_package(gazebo_ros REQUIRED)
find_package(pluginlib REQUIRED)
find_package(rclcpp REQUIRED)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wconversion -Wno-sign-conversion -Wpedantic -Wnon-virtual-dtor -Woverloaded-virtual)
endif()

include_directories(include)

# Libraries
add_library(${PROJECT_NAME} SHARED
  src/rrmagnobot_gazebo_force_plugin.cpp
)

ament_target_dependencies(${PROJECT_NAME}
  gazebo_ros
  pluginlib
  rclcpp
)

## Install
install(TARGETS
  ${PROJECT_NAME}
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
