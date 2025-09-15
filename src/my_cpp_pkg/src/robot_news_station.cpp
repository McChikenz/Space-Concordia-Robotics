#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp" 

using namespace std::chrono_literals; //for using time literals like 500ms
     
class RobotNewsStationNode: public rclcpp::Node { // Create a class that inherits from rclcpp::Node
    public:
        RobotNewsStationNode() : Node("robot_news_station") { 
            publisher_ = this->create_publisher<example_interfaces::msg::String>("robot_news", 10); 
            timer_ = this->create_wall_timer(500ms, std::bind(&RobotNewsStationNode::publishNews, this));
            RCLCPP_INFO(this->get_logger(), "Robot News Station node has been started from CPP!");
        }
     
    private:
        void publishNews() {
            auto message = example_interfaces::msg::String();
            message.data = "Hello from Robot News Station from CPP!"; //Message content
            RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str()); // log message
            publisher_->publish(message); // Publish message
        }
        rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_; //Publisher object
        rclcpp::TimerBase::SharedPtr timer_ ;
};
     
int main(int argc, char **argv){
    rclcpp::init(argc, argv); // Initialize ROS2
    auto node = std::make_shared<RobotNewsStationNode>(); // Create node 
    rclcpp::spin(node); // Keep node alive to listen for messages
    rclcpp::shutdown(); // Shutdown ROS2
    return 0;
}
