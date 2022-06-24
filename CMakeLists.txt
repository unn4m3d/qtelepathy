cmake_minimum_required(VERSION 3.15)
project(qtelepathy)
enable_testing()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Network Test)
add_library(qtelepathy_static STATIC qtelepathy.cpp)
add_definitions(-DQT_NO_KEYWORDS)
target_link_libraries(qtelepathy_static Qt5::Core Qt5::Network)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(test1 test1.cpp)
target_link_libraries(test1 Qt5::Test qtelepathy_static)
add_test(NAME test COMMAND test1)