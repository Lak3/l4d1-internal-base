#include "Interface.h"

void* CUtil_Interface::GetInterface(const HMODULE hModule, const char* const szObject)
{
	const FARPROC pfCreateAddr = GetProcAddress(hModule, "CreateInterface");

	if (!pfCreateAddr)
		return nullptr;

	const auto pfCreateInterface = reinterpret_cast<void* (*)(const char*, int*)>(pfCreateAddr);

	if (!pfCreateInterface)
		return nullptr;

	return pfCreateInterface(szObject, nullptr);
}