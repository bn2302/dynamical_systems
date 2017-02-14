include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include
	../${CMAKE_CURRENT_SOURCE_DIR}/systems/include
)

set(library_SRC
    integrator.cc
    rungekutta4.cc
)

add_library (integrators SHARED ${library_SRC})


install(TARGETS integrators
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION bin
)
