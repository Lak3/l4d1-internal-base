#include "Hooks.h"

using namespace Hooks;

void CGlobal_Hooks::Init()
{
	const MH_STATUS MH_INIT_STATUS = MH_Initialize();
	XASSERT(MH_INIT_STATUS != MH_STATUS::MH_OK);

	if (MH_INIT_STATUS == MH_STATUS::MH_OK)
	{
		BaseAnimating::Init();
		BasePlayer::Init();
		CL_Main::Init();
		Client::Init();
		ClientPrediction::Init();
		EngineVGui::Init();
		ModelRender::Init();
		ModelRenderSystem::Init();
		SequenceTransitioner::Init();
		TerrorClientMode::Init();
		TerrorGun::Init();
		TerrorPlayer::Init();
		VGuiPanel::Init();
		VGuiSurface::Init();
		WndProc::Init();
	}

	XASSERT(MH_EnableHook(MH_ALL_HOOKS) != MH_STATUS::MH_OK);
}