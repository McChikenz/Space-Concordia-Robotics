#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String
     
     
class SmartphoneNode(Node):
    def __init__(self):
        super().__init__("smartphone")  #  Name of the node
        self.subscriber = self.create_subscription(String, "robot_news", self.callback_robot_news, 10) # create a subscription to the "robot_news" topic
        self.get_logger().info("Smartphone node has been started from python!") 
        
    def callback_robot_news(self, msg: String):
        self.get_logger().info(msg.data) # log the received message

     
def main(args=None):
    rclpy.init(args=args) # initialize rclpy
    node = SmartphoneNode() # create node instance
    rclpy.spin(node) # keep node alive to listen to messages
    rclpy.shutdown()
     
if __name__ == "__main__":
    main()
