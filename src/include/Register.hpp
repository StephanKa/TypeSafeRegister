#pragma once
#ifdef _WIN32
#include "WinRegister.hpp"
#elif linux
#include "WinRegister.hpp"
#else
#include "McuRegister.hpp"
#endif
