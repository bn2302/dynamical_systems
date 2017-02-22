include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/lib/integrators/
	${CMAKE_CURRENT_SOURCE_DIR}/lib/systems/
)


set(simulate_SRC
    simulate_pendulum.cc
)

add_executable (simulate_pendulum ${simulate_SRC})

link_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/lib/integrators/
	${CMAKE_CURRENT_SOURCE_DIR}/lib/systems/
)
target_link_libraries(simulate_pendulum
    systems
)

install(TARGETS simulate_pendulum
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION bin
)

add_subdirectory(
	${CMAKE_CURRENT_SOURCE_DIR}/lib)
