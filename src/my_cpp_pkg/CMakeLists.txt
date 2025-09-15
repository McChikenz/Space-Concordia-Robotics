cmake_minimum_required(VERSION 3.8)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

# for robot_news_station
add_executable(robot_news_station src/robot_news_station.cpp)
ament_target_dependencies(robot_news_station rclcpp example_interfaces)

# for smartphone
add_executable(smartphone src/smartphone.cpp)
ament_target_dependencies(smartphone rclcpp example_interfaces)

install(TARGETS
  robot_news_station
  smartphone
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
