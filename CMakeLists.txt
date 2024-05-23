cmake_minimum_required(VERSION 3.15)

project(cash-machine LANGUAGES CXX)
enable_testing()

set(SOURCE_FILES
    src/cashmachine.cpp
)

add_subdirectory(test)

add_library(cash-machine ${SOURCE_FILES})

add_test(NAME Test1 COMMAND $<TARGET_FILE:cash-machine-test1>)
add_test(NAME Test2 COMMAND $<TARGET_FILE:cash-machine-test2>)
add_test(NAME Test3 COMMAND $<TARGET_FILE:cash-machine-test3>)
add_test(NAME Test4 COMMAND $<TARGET_FILE:cash-machine-test4>)
