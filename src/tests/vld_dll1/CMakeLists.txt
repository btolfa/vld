cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(vld_dll1 CXX)

add_library(vld_dll1 SHARED dllmain.cpp stdafx.cpp stdafx.h targetver.h)
target_compile_definitions(vld_dll1 PRIVATE UNICODE _UNICODE)
target_link_libraries(vld_dll1 PRIVATE vld)