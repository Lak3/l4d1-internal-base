#include "BaseAnimating.h"

using namespace Hooks;

void __fastcall BaseAnimating::BuildTransformations::Detour(C_BaseAnimating* pThis, void* edx, CStudioHdr* hdr, void* pos, void* q, const matrix3x4_t& cameraTransform, int boneMask, void* boneComputed)
{
	Func.Original<FN>()(pThis, edx, hdr, pos, q, cameraTransform, boneMask, boneComputed);
}

void __fastcall BaseAnimating::StandardBlendingRules::Detour(C_BaseAnimating* pThis, void* edx, CStudioHdr* hdr, Vector pos[], void* q, float currentTime, int boneMask)
{
	Func.Original<FN>()(pThis, edx, hdr, pos, q, currentTime, boneMask);
}

IClientModelRenderable* __fastcall BaseAnimating::GetClientModelRenderable::Detour(C_BaseAnimating* pThis, void* edx)
{
	//This commented example below is one way to make infected go trough DME.
	/*
	if (pThis)
	{
		ClientClass* pCC = pThis->GetClientClass();
		
		if (pCC && (pCC->m_ClassID == Infected))
			return NULL;
	}
	*/

	return Func.Original<FN>()(pThis, edx);
}

void BaseAnimating::Init()
{
	//BuildTransformations
	{
		using namespace BuildTransformations;

		const FN pfBuildTransformations = reinterpret_cast<FN>(U::Offsets.m_dwBuildTransFormations);
		XASSERT(pfBuildTransformations == nullptr);

		if (pfBuildTransformations)
			XASSERT(Func.Init(pfBuildTransformations, &Detour) == false);
	}

	//StandardBlendingRules
	{
		using namespace StandardBlendingRules;

		const FN pfStandardBlendingRules = reinterpret_cast<FN>(U::Offsets.m_dwStandardBlendingRules);
		XASSERT(pfStandardBlendingRules == nullptr);

		if (pfStandardBlendingRules)
			XASSERT(Func.Init(pfStandardBlendingRules, &Detour) == false);
	}

	//GetClientModelRenderable
	{
		using namespace GetClientModelRenderable;

		const FN pfGetClientModelRenderable = reinterpret_cast<FN>(U::Offsets.m_dwGetClientModelRenderable);
		XASSERT(pfGetClientModelRenderable == 0x0);

		if (pfGetClientModelRenderable)
			XASSERT(Func.Init(pfGetClientModelRenderable, &Detour) == false);
	}
}