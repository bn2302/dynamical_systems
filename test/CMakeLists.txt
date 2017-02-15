add_subdirectory(
	${CMAKE_BINARY_DIR}/googletest-src
	${CMAKE_BINARY_DIR}/googletest-build
	)

include_directories(
	${GTEST_INCLUDE_DIRS} ${COMMON_INCLUDES} 
	${gtest_SOURCE_DIR}/include
	)


file(GLOB_RECURSE SRCS *.cc)

add_executable(test_dynamical_system ${SRCS})

target_link_libraries(test_dynamical_system
	gtest_main
	systems
	integrators
)

add_test(TARGETS test_dynamical_system)


