#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String
     
     
class RobotNewsStation(Node):
    def __init__(self):
        super().__init__("robot_news_station") 
        self.publisher_ = self.create_publisher(String, "robot_news", 10)
        self.timer_ = self.create_timer(0.5, self.publish_news)
        self.get_logger().info("Robot News Station has been started from python!")
     
    def publish_news(self):
        msg = String()
        msg.data = "Hello, this is your robot news station from python!"
        self.publisher_.publish(msg)
     
def main(args=None):
    rclpy.init(args=args) # initialize rclpy
    node = RobotNewsStation() # create node instance
    rclpy.spin(node) # keep node alive to listen to messages
    rclpy.shutdown()
     
if __name__ == "__main__":
    main()