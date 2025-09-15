#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp" // MODIFY MESSAGE TYPE IF NEEDED

using namespace std::chrono_literals;
     
class RobotNewsStationNode: public rclcpp::Node { //
    public:
        RobotNewsStationNode() : Node("robot_news_station") { // MODIFY NAME
            publisher_ = this->create_publisher<example_interfaces::msg::String>("robot_news", 10); 
            timer_ = this->create_wall_timer(500ms, std::bind(&RobotNewsStationNode::publishNews, this));
            RCLCPP_INFO(this->get_logger(), "Robot News Station node has been started from CPP!");
        }
     
    private:
        void publishNews() {
            auto message = example_interfaces::msg::String();
            message.data = "Hello from Robot News Station from CPP!"; // MODIFY MESSAGE CONTENT IF NEEDED
            RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
            publisher_->publish(message);
        }
        rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_ ;
};
     
int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotNewsStationNode>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}