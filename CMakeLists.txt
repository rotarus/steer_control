cmake_minimum_required(VERSION 3.5)
project(steer_control)



# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(lgsvl_msgs REQUIRED)

add_executable(steering src/CPP_Steer_Ang.cpp)
ament_target_dependencies(steering rclcpp std_msgs lgsvl_msgs) # std_msg yerine lgsvl_msg kullanılabilir.

install(TARGETS
  steering
  DESTINATION lib/${PROJECT_NAME})
  

ament_package()
