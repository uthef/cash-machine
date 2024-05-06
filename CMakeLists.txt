cmake_minimum_required(VERSION 3.5)

project(cash-machine LANGUAGES CXX)
enable_testing()

set(SOURCE_FILES
    cashmachine.cpp
)

add_subdirectory(test)

add_library(cash-machine ${SOURCE_FILES})

add_test(NAME Test COMMAND $<TARGET_FILE:cash-machine-test>)
