cmake_minimum_required(VERSION 3.12)
project(LIN_Bus_gtest VERSION 0.1.0)

add_executable(${PROJECT_NAME}_master test_master.cpp)
target_link_libraries(${PROJECT_NAME}_master PUBLIC LIN_master GTest::GTest)

add_test(test_master ${PROJECT_NAME}_master)