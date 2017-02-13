set(library_SRC
    dynamical_system.cc
    pendulum.cc
    integrator.cc
    rungekutta4.cc
)

add_library (integration SHARED ${library_SRC})


install(TARGETS integration
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
)
