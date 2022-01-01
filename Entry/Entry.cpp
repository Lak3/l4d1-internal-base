#include "Entry.h"

void CGlobal_ModuleEntry::Load()
{
	while (!GetModuleHandleA("serverbrowser.dll"))
		std::this_thread::sleep_for(std::chrono::seconds(1));

	U::Offsets.Init();

	//Interfaces
	{
		I::BaseClient   = U::Interface.Get<IBaseClientDll*>("client.dll", "VClient016");
		I::EntityList   = U::Interface.Get<IClientEntityList*>("client.dll", "VClientEntityList003");
		I::Prediction   = U::Interface.Get<IPrediction*>("client.dll", "VClientPrediction001");
		I::GameMovement = U::Interface.Get<IGameMovement*>("client.dll", "GameMovement001");

		I::EngineClient = U::Interface.Get<IVEngineClient*>("engine.dll", "VEngineClient013");
		I::EngineTrace  = U::Interface.Get<IEngineTrace*>("engine.dll", "EngineTraceClient003");
		I::EngineVGui   = U::Interface.Get<IEngineVGui*>("engine.dll", "VEngineVGui001");
		I::RenderView   = U::Interface.Get<IVRenderView*>("engine.dll", "VEngineRenderView013");
		I::DebugOverlay = U::Interface.Get<IVDebugOverlay*>("engine.dll", "VDebugOverlay003");
		I::ModelInfo    = U::Interface.Get<IVModelInfo*>("engine.dll", "VModelInfoClient004");
		I::ModelRender = U::Interface.Get<IVModelRender*>("engine.dll", "VEngineModel016");

		I::VGuiPanel   = U::Interface.Get<IVGuiPanel*>("vgui2.dll", "VGUI_Panel009");
		I::VGuiSurface = U::Interface.Get<IVGuiSurface*>("vgui2.dll", "VGUI_Surface030");

		I::MatSystemSurface = U::Interface.Get<IMatSystemSurface*>("vguimatsurface.dll", "VGUI_Surface030");

		I::MaterialSystem = U::Interface.Get<IMaterialSystem*>("materialsystem.dll", "VMaterialSystem080");

		I::GlobalVars = reinterpret_cast<CGlobalVarsBase*>(reinterpret_cast<DWORD>(GetModuleHandleA("client.dll")) + (0x5A5A04 - 0xC));
		XASSERT(I::GlobalVars == nullptr);
	}

	G::Draw.Init();
	G::Hooks.Init();
}