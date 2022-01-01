#include "Entry/Entry.h"

static bool g_bAttached = false;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if ((fdwReason == DLL_PROCESS_ATTACH) && !g_bAttached) {
		G::ModuleEntry.Load();
		g_bAttached = true;
	}

	return TRUE;
}