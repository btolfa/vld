cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(vld_main CXX)

add_executable(vld_main WIN32 stdafx.h stdafx.cpp targetver.h vld_main.cpp)
target_link_libraries(vld_main PRIVATE vld)
target_compile_definitions(vld_main PRIVATE UNICODE _UNICODE)
