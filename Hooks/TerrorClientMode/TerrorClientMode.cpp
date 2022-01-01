#include "TerrorClientMode.h"

using namespace Hooks;

void __fastcall TerrorClientMode::DoPostScreenSpaceEffects::Detour(void* ecx, void* edx, const void* pSetup)
{
	Func.Original<FN>()(ecx, edx, pSetup);
}

//Args straight from IDA
void __fastcall TerrorClientMode::ApplyEntityGlowEffects::Detour(void* ecx, void* edx, int a3, int a4, float a5, float a6, int a7, int a8, int a9)
{
	Func.Original<FN>()(ecx, edx, a3, a4, a5, a6, a7, a8, a9);
}

float __fastcall TerrorClientMode::GetViewModelFOV::Detour(void* ecx, void* edx)
{
	return Func.Original<FN>()(ecx, edx);
}

void TerrorClientMode::Init()
{
	//DoPostScreenSpaceEffects
	{
		using namespace DoPostScreenSpaceEffects;

		const FN pfDoPostScreenSpaceEffects = reinterpret_cast<FN>(U::Offsets.m_dwDoPostScreenSpaceEffects);
		XASSERT(pfDoPostScreenSpaceEffects == nullptr);

		if (pfDoPostScreenSpaceEffects)
			XASSERT(Func.Init(pfDoPostScreenSpaceEffects, &Detour) == false);
	}

	//ApplyEntityGlowEffects
	{
		using namespace ApplyEntityGlowEffects;

		const FN pfApplyEntityGlowEffects = reinterpret_cast<FN>(U::Offsets.m_dwApplyEntityGlowEffects);
		XASSERT(pfApplyEntityGlowEffects == nullptr);

		if (pfApplyEntityGlowEffects)
			XASSERT(Func.Init(pfApplyEntityGlowEffects, &Detour) == false);
	}

	//GetViewModelFOV
	{
		using namespace GetViewModelFOV;

		const FN pfGetViewModelFOV = reinterpret_cast<FN>(U::Offsets.m_dwGetViewmodelFov);
		XASSERT(pfGetViewModelFOV == nullptr);

		if (pfGetViewModelFOV)
			XASSERT(Func.Init(pfGetViewModelFOV, &Detour) == false);
	}
}