#pragma once
#ifdef _WIN32 || linux
#include "WinRegister.hpp"
#else
#include "McuRegister.hpp"
#endif