cmake_minimum_required(VERSION 3.10)
project(TrainStation)

set(CMAKE_CXX_STANDARD 17)

# Add include directory
include_directories(include)

# Add all cpp files in src/
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(TrainStation ${SOURCES})
