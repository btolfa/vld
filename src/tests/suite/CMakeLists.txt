cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(suite CXX)

add_executable(suite testsuite.cpp)

target_link_libraries(suite PRIVATE gtest vld)

set(DLL_DIR ${CMAKE_VS_PLATFORM_NAME})
if (DLL_DIR STREQUAL "Win32")
    set(DLL_DIR "x86")
endif()

add_custom_command(TARGET suite POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../../vld.ini $<TARGET_FILE_DIR:suite>
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:vld> $<TARGET_FILE_DIR:suite>
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_PDB_FILE:vld> $<TARGET_FILE_DIR:suite>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../../setup/dbghelp/${DLL_DIR}/dbghelp.dll $<TARGET_FILE_DIR:suite>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../../setup/dbghelp/${DLL_DIR}/Microsoft.Windows.DebuggersAndTools.manifest $<TARGET_FILE_DIR:suite>
)

add_test(NAME suite COMMAND suite)
