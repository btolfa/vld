cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(vld_main_test CXX)

add_executable(vld_main_test stdafx.h stdafx.cpp targetver.h vld_main_test.cpp)

target_compile_definitions(vld_main_test PRIVATE UNICODE _UNICODE)
target_link_libraries(vld_main_test PRIVATE gtest vld)
add_dependencies(vld_main_test vld_main)

set(DLL_DIR ${CMAKE_VS_PLATFORM_NAME})
if (DLL_DIR STREQUAL "Win32")
    set(DLL_DIR "x86")
endif()

add_custom_command(TARGET vld_main_test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../../vld.ini $<TARGET_FILE_DIR:vld_main_test>
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:vld> $<TARGET_FILE_DIR:vld_main_test>
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_PDB_FILE:vld> $<TARGET_FILE_DIR:vld_main_test>
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:vld_main> $<TARGET_FILE_DIR:vld_main_test>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../../setup/dbghelp/${DLL_DIR}/dbghelp.dll $<TARGET_FILE_DIR:vld_main_test>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../../setup/dbghelp/${DLL_DIR}/Microsoft.Windows.DebuggersAndTools.manifest $<TARGET_FILE_DIR:vld_main_test>
)

add_test(NAME vld_main_test COMMAND vld_main_test)
