cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(tests CXX)

add_subdirectory(basics)
add_subdirectory(corruption)
add_subdirectory(dynamic_dll)
add_subdirectory(dynamic_app)
add_subdirectory(suite)
add_subdirectory(vld_main)
add_subdirectory(vld_main_test)
add_subdirectory(vld_dll1)
add_subdirectory(vld_dll2)
add_subdirectory(vld_unload)
