cmake_minimum_required(VERSION 3.15)

project(cash-machine-test1)
project(cash-machine-test2)
project(cash-machine-test3)
project(cash-machine-test4)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(cash-machine-test1
    test1.cpp
)

add_executable(cash-machine-test2
    test2.cpp
)

add_executable(cash-machine-test3
    test3.cpp
)

add_executable(cash-machine-test4
    test4.cpp
)

target_link_libraries(cash-machine-test1 PRIVATE cash-machine)
target_link_libraries(cash-machine-test2 PRIVATE cash-machine)
target_link_libraries(cash-machine-test3 PRIVATE cash-machine)
target_link_libraries(cash-machine-test4 PRIVATE cash-machine)
