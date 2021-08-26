#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <math.h>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "lgsvl_msgs/msg/vehicle_control_data.hpp"




using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class SteerAngleNode : public rclcpp::Node
{
  public:
    SteerAngleNode() : Node("steer_angle"), count_(0)
    {
      publisher_ = this->create_publisher<lgsvl_msgs::msg::VehicleControlData>("steer_ang", 10);
      timer_ = this->create_wall_timer(100ms, std::bind(&SteerAngleNode::timer_callback, this));
      RCLCPP_INFO(this-> get_logger(), "Steer Angle Has Been Started!");

    }

  private:
    void timer_callback()
    { 
      timer++;    
      msg.target_wheel_angle = sin((M_PI/180)* timer);
      publisher_->publish(msg);
    }
    int timer;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<lgsvl_msgs::msg::VehicleControlData>::SharedPtr publisher_;
    size_t count_ ;
    lgsvl_msgs::msg::VehicleControlData msg;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SteerAngleNode>(); 
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}