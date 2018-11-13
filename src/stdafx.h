#pragma once

#include <cassert>
#include <cerrno>
#include <cstdio>
#include <winsock2.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")  
#include <winternl.h>
#ifndef __out_xcount
#define __out_xcount(x) // Workaround for the specstrings.h bug in the Platform SDK.
#endif
#define DBGHELP_TRANSLATE_TCHAR
#include "dbghelp.h"    // Provides portable executable (PE) image access functions.
