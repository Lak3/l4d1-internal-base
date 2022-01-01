#pragma once

#include "../Hook/Hook.h"

#define XASSERT(x) if (x) MessageBoxA(HWND_DESKTOP, #x, "FATAL ERROR", MB_ICONERROR)

class CUtil_Pattern
{
public:
	DWORD Find(const char* const szModule, const char* const szPattern);

private:
	DWORD FindPattern(const DWORD dwAddress, const DWORD dwLen, const char* const szPattern);
};

namespace U { inline CUtil_Pattern Pattern; }