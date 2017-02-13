include_directories(
    ${CMAKE_SOURCE_DIR}/lib
)

set(simulate_SRC
    simulate_pendulum.cc
)

add_executable (simulate_pendulum ${simulate_SRC})

target_link_libraries(simulate_pendulum
    integration
)

install(TARGETS simulate_pendulum
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
)
