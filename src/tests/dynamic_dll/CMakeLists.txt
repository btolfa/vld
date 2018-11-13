cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(dynamic_dll CXX)

add_library(dynamic SHARED dllmain.cpp dynamic.cpp dynamic.h stdafx.cpp stdafx.h targetver.h ../basics/Allocs.cpp ../basics/Allocs.h)
target_link_libraries(dynamic PRIVATE gtest vld)

target_compile_definitions(dynamic PRIVATE DYNAMIC_EXPORTS)