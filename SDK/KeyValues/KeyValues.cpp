#pragma once

#include "KeyValues.h"

bool CGlobal_KeyValues::LoadFromBuffer(KeyValues* pKval, const char* const szName, const char* const szBuff, void* pSys, const char* const szPath)
{
	static const DWORD dwLoadFromBuffer = U::Pattern.Find("client.dll", "83 EC 30 55 56 8B 74 24 40 85 F6 8B E9 75 0A");
	XASSERT(dwLoadFromBuffer == 0x0);

	if (!dwLoadFromBuffer)
		return false;

	return reinterpret_cast<int(__thiscall*)(KeyValues*, char const*, const char*, void*, const char*)>(dwLoadFromBuffer)(pKval, szName, szBuff, pSys, szPath);
}

KeyValues* CGlobal_KeyValues::Init(KeyValues* pKval, const char* const szName)
{
	static const DWORD dwKeyValsInit = U::Pattern.Find("client.dll", "33 C0 56 8B F1 C7 06 ? ? ? ? 88 46 10 89 46 18 89 46 14 89 46 1C 89 46 04 89 46 08 89 46 0C 88 46 11 89 46 20 66 89 46 12 FF 15 ? ? ? ? 8B 4C 24 08 8B 10 8B 52 0C 6A 01 51 8B C8 FF D2 89 06 8B C6 5E C2 04 00");
	XASSERT(dwKeyValsInit == 0x0);

	if (!dwKeyValsInit)
		return nullptr;

	return reinterpret_cast<KeyValues* (__thiscall*)(KeyValues*, const char*)>(dwKeyValsInit)(pKval, szName);
}