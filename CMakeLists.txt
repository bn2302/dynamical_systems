Project(dynamical_system_simulator)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
# set(CMAKE_CXX_EXTENSIONS OFF) #...
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")

add_subdirectory(lib)
add_subdirectory(src)


