cmake_minimum_required(VERSION 2.8.11)
set(PROJECT_NAME_STR dynamical_system_simulator)
project(${PROJECT_NAME_STR} C CXX)


set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")


set(COMMON_INCLUDES 
	${PROJECT_SOURCE_DIR}/src/lib/integrators/include 
	${PROJECT_SOURCE_DIR}/src/lib/systems/include
	)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
	RESULT_VARIABLE result
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
	message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
	RESULT_VARIABLE result
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
	message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

enable_testing()
add_subdirectory(${PROJECT_SOURCE_DIR}/test)

