cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

project(gtest CXX)

add_library(gtest STATIC gtest/gtest.h gtest/gtest-spi.h gmock/gmock.h gmock-gtest-all.cc)

target_include_directories(gtest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})