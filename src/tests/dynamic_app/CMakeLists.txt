cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(dynamicapp CXX)

add_executable(dynamicapp stdafx.h stdafx.cpp targetver.h LoadTests.cpp LoadTests.h ThreadTest.cpp ThreadTests.h dynamic_app.cpp)

target_link_libraries(dynamicapp PRIVATE gtest vld dynamic)
target_compile_definitions(dynamicapp PRIVATE UNICODE _UNICODE)

set(DLL_DIR ${CMAKE_VS_PLATFORM_NAME})
if (DLL_DIR STREQUAL "Win32")
    set(DLL_DIR "x86")
endif()

add_custom_command(TARGET dynamicapp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../../vld.ini $<TARGET_FILE_DIR:dynamicapp>
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:vld> $<TARGET_FILE_DIR:dynamicapp>
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_PDB_FILE:vld> $<TARGET_FILE_DIR:dynamicapp>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../../setup/dbghelp/${DLL_DIR}/dbghelp.dll $<TARGET_FILE_DIR:dynamicapp>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/../../../setup/dbghelp/${DLL_DIR}/Microsoft.Windows.DebuggersAndTools.manifest $<TARGET_FILE_DIR:dynamicapp>
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:dynamic> $<TARGET_FILE_DIR:dynamicapp>
)

add_test(NAME dynamicapp COMMAND dynamicapp)