#pragma once
#ifdef _WIN32
#include "desktop/registerImpl.hpp"
#elif linux
#include "desktop/registerImpl.hpp"
#else
#include "mcu/registerImpl.hpp"
#endif
