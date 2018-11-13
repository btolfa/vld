cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(basics CXX)

add_executable(basics
    Allocs.cpp
    Allocs.h
    basics_disabled.cpp
    basics.cpp
    stdafx.cpp
    stdafx.h
    targetver.h
)

target_link_libraries(basics PRIVATE gtest vld)

set(DLL_DIR ${CMAKE_VS_PLATFORM_NAME})
if (DLL_DIR STREQUAL "Win32")
    set(DLL_DIR "x86")
endif()

add_custom_command(TARGET basics POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../../vld.ini $<TARGET_FILE_DIR:basics>
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:vld> $<TARGET_FILE_DIR:basics>
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_PDB_FILE:vld> $<TARGET_FILE_DIR:basics>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../../setup/dbghelp/${DLL_DIR}/dbghelp.dll $<TARGET_FILE_DIR:basics>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../../setup/dbghelp/${DLL_DIR}/Microsoft.Windows.DebuggersAndTools.manifest $<TARGET_FILE_DIR:basics>
)

add_test(NAME basics COMMAND basics)