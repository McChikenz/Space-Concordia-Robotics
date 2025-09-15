#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String
     
     
class RobotNewsStation(Node):
    def __init__(self):
        super().__init__("robot_news_station") # node name
        self.publisher_ = self.create_publisher(String, "robot_news", 10)  # create publisher
        self.timer_ = self.create_timer(0.5, self.publish_news)  # create timer to call publish_news every 0.5 seconds
        self.get_logger().info("Robot News Station has been started from python!")# log info message
     
    def publish_news(self): # function to publish news
        msg = String() # create a String message
        msg.data = "Hello, this is your robot news station from python!"
        self.publisher_.publish(msg) # publish the msg
     
def main(args=None):
    rclpy.init(args=args) # initialize rclpy
    node = RobotNewsStation() # create node instance
    rclpy.spin(node) # keep node alive to listen to messages
    rclpy.shutdown() # shutdown ROS2
     
if __name__ == "__main__":
    main()
