cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(fmt
        VERSION 1.1.0
        DESCRIPTION "fmt is an open-source formatting library for C++"
        HOMEPAGE_URL "http://fmtlib.net"
        LANGUAGES CXX)

add_library(fmt format.cc posix.cc format.h posix.h)
target_include_directories(fmt INTERFACE ..)