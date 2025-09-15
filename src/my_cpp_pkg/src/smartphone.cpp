#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp" 

using namespace std::placeholders;  // for "_1"
     
class SmartphoneNode : public rclcpp::Node { 
    public:
        SmartphoneNode() : Node("smartphone") { // MODIFY NAME
            subscriber_ =this->create_subscription<example_interfaces::msg::String>("robot_news", 10, std::bind(&SmartphoneNode::callBackRobotNews, this, _1)); // create a subscription to the "robot_news" topic
            RCLCPP_INFO(this->get_logger(), "Smartphone node has been started from CPP!");
        }
     
    private:
        void callBackRobotNews(const example_interfaces::msg::String::SharedPtr msg) {
            RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str()); // log the received message
        }
        rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscriber_; // Subscription object
};
     
int main(int argc, char **argv){
    rclcpp::init(argc, argv); // initialize ROS2
    auto node = std::make_shared<SmartphoneNode>(); // Create Node
    rclcpp::spin(node); // keep the node alive to listen for messages
    rclcpp::shutdown(); // Shutdown ROS2
    return 0;
}
