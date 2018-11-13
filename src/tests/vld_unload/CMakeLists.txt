cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(vld_unload CXX)

add_executable(vld_unload stdafx.h stdafx.cpp targetver.h vld_unload.cpp)

target_link_libraries(vld_unload PRIVATE gtest vld)
add_dependencies(vld_unload vld_dll1 vld_dll2)

set(DLL_DIR ${CMAKE_VS_PLATFORM_NAME})
if (DLL_DIR STREQUAL "Win32")
    set(DLL_DIR "x86")
endif()

add_custom_command(TARGET vld_unload POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../../vld.ini $<TARGET_FILE_DIR:vld_unload>
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:vld> $<TARGET_FILE_DIR:vld_unload>
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_PDB_FILE:vld> $<TARGET_FILE_DIR:vld_unload>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../../setup/dbghelp/${DLL_DIR}/dbghelp.dll $<TARGET_FILE_DIR:vld_unload>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../../setup/dbghelp/${DLL_DIR}/Microsoft.Windows.DebuggersAndTools.manifest $<TARGET_FILE_DIR:vld_unload>
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:vld_dll1> $<TARGET_FILE_DIR:vld_unload>
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:vld_dll2> $<TARGET_FILE_DIR:vld_unload>
)

add_test(NAME vld_unload COMMAND vld_unload)