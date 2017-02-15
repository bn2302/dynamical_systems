include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/lib/integrators/include
	${CMAKE_CURRENT_SOURCE_DIR}/lib/systems/include
)


set(simulate_SRC
    simulate_pendulum.cc
)

add_executable (simulate_pendulum ${simulate_SRC})

target_link_libraries(simulate_pendulum
    integrators
    systems
)

install(TARGETS simulate_pendulum
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION bin
)

add_subdirectory(
	${CMAKE_CURRENT_SOURCE_DIR}/lib)
