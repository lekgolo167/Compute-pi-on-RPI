cmake_minimum_required (VERSION 3.0)
project (ComputePi)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++11 -pthread -O3 ${CMAKE_CXX_FLAGS}")
endif()

add_executable(ComputePi
	main.cpp
	computePi.cpp
	computePi.hpp
	mutex.cpp
	mutex.hpp

    # Add files implementing your thread-safe data structures below
)

