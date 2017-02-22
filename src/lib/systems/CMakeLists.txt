include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

set(library_SRC
    dynamical_system.cc
    pendulum.cc
    double_pendulum.cc
)

add_library (systems STATIC ${library_SRC})

