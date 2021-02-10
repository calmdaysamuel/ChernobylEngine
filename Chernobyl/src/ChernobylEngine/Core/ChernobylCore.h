#pragma once

#ifdef BUILD_DLL
#define CHERNOBYL_API __declspec(dllexport)
#else
#define CHERNOBYL_API __declspec(dllimport)
#endif // BUILD_DLL

#include "Utilities/Utils.h"