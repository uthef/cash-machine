cmake_minimum_required(VERSION 3.5)
project(cash-machine-test)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(cash-machine-test
    test.cpp
)

target_link_libraries(cash-machine-test cash-machine)
