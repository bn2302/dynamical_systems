# Dynamical simulator in C++

C++14 implementation of a template based integrator class, which takes function
pointers or classes with an overloaded () operator as a argument. The function
pointers or classes () method implements the dynamical system.

As an example a single and double pendulum is implemented.

Tests have been implemented using googletest

Compiled on  Windows 10 x64 using Visual Studio 2015

