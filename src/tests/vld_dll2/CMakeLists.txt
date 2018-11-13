cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(vld_dll2 CXX)

add_library(vld_dll2 SHARED dllmain.cpp stdafx.cpp stdafx.h targetver.h)
target_compile_definitions(vld_dll2 PRIVATE UNICODE _UNICODE)
target_link_libraries(vld_dll2 PRIVATE vld)