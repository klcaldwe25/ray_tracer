cmake_minimum_required(VERSION 3.12) # version can be different

project(ray_tracer) #name of your project

include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(googletest)