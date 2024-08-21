cmake_minimum_required (VERSION 3.1)
project (init_project)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_BUILD_TYPE Debug)


include_directories(include)

add_executable(rock_paper_scissors src/rock_paper_scissors.cpp)
add_executable(find_number src/find_number.cpp )
add_executable(sticks src/sticks.cpp include/sticks.h)



