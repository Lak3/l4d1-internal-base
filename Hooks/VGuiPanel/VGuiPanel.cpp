#include "VGuiPanel.h"

#include "../../Features/Vars.h"

using namespace Hooks;

void __fastcall VGuiPanel::PaintTraverse::Detour(void* ecx, void* edx, VPANEL vguiPanel, bool forceRepaint, bool allowForce)
{
	Table.Original<FN>(Index)(ecx, edx, vguiPanel, forceRepaint, allowForce);
}

void VGuiPanel::Init()
{
	XASSERT(Table.Init(I::VGuiPanel) == false);
	XASSERT(Table.Hook(&PaintTraverse::Detour, PaintTraverse::Index) == false);
}