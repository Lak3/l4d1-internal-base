#include "VGuiSurface.h"

#include "../../Features/Vars.h"

using namespace Hooks;

void __fastcall VGuiSurface::LockCursor::Detour(void* ecx, void* edx)
{
	Table.Original<FN>(Index)(ecx, edx);
}

void VGuiSurface::Init()
{
	XASSERT(Table.Init(I::VGuiSurface) == false);
	XASSERT(Table.Hook(&LockCursor::Detour, LockCursor::Index) == false);
}