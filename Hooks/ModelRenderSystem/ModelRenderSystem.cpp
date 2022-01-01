#include "ModelRenderSystem.h"

using namespace Hooks;

void __fastcall ModelRenderSystem::DrawModels::Detour(void* ecx, void* edx, ModelRenderSystemData_t* pEntities, int nCount, int renderMode)
{
	/*
		Here you can build your own renderlist of the pEntities argument and filter out entities you dont want to render,
		or ones that you have already rendered yourself and want to prevent the game from rendering them a second time.
	*/

	Func.Original<FN>()(ecx, edx, pEntities, nCount, renderMode);
}

void ModelRenderSystem::Init()
{
	//DrawModels
	{
		using namespace DrawModels;

		const FN pfDrawModels = reinterpret_cast<FN>(U::Offsets.m_dwDrawModels);
		XASSERT(pfDrawModels == nullptr);

		if (pfDrawModels)
			XASSERT(Func.Init(pfDrawModels, &Detour) == false);
	}
}