include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(library_SRC
    dynamical_system.cc
    pendulum.cc
    double_pendulum.cc
)

add_library (systems SHARED ${library_SRC})


install(TARGETS systems
	RUNTIME DESTINATION bin
        LIBRARY DESTINATION bin
)
