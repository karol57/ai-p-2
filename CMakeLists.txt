cmake_minimum_required(VERSION 3.15.5)
project(SIProj2)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG  "-ggdb3")

find_package(Boost REQUIRED program_options)

add_executable(SIProj2 main.cpp Application.cpp)
target_include_directories(SIProj2 SYSTEM PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(SIProj2 ${Boost_LIBRARIES})
