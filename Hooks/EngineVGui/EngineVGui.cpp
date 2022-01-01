#include "EngineVGui.h"

#include "../../Features/ESP/ESP.h"

using namespace Hooks;

void __fastcall EngineVGui::Paint::Detour(void* ecx, void* edx, int mode)
{
	Table.Original<FN>(Index)(ecx, edx, mode);

	if (mode & PaintMode_t::PAINT_UIPANELS)
	{
		if (!G::Draw.m_nScreenW)
			G::Draw.m_nScreenW = I::BaseClient->GetScreenWidth();

		if (!G::Draw.m_nScreenH)
			G::Draw.m_nScreenH = I::BaseClient->GetScreenHeight();

		I::MatSystemSurface->StartDrawing();
		{
			F::ESP.Render();

			G::Draw.String(EFonts::DEBUG, 5, 5, { 204, 204, 204, 255 }, TXT_DEFAULT, L"Polonium - Left 4 dead by Lak3 (unknowncheats.me)");
		}
		I::MatSystemSurface->FinishDrawing();
	}
}

void EngineVGui::Init()
{
	XASSERT(Table.Init(I::EngineVGui) == false);
	XASSERT(Table.Hook(&Paint::Detour, Paint::Index) == false);
}