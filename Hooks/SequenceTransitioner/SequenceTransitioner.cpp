#include "SequenceTransitioner.h"

#include "../../Features/Vars.h"

using namespace Hooks;

void __fastcall SequenceTransitioner::CheckForSequenceChange::Detour(void* ecx, void* edx, CStudioHdr* hdr, int nCurSequence, bool bForceNewSequence, bool bInterpolate)
{
	Func.Original<FN>()(ecx, edx, hdr, nCurSequence, bForceNewSequence, bInterpolate);
}

void __fastcall SequenceTransitioner::UpdateCurrent::Detour(void* ecx, void* edx, CStudioHdr* hdr, int nCurSequence, float flCurCycle, float flCurPlaybackRate, float flCurTime)
{
	Func.Original<FN>()(ecx, edx, hdr, nCurSequence, flCurCycle, flCurPlaybackRate, flCurTime);
}

void SequenceTransitioner::Init()
{
	//CheckForSequenceChange
	{
		using namespace CheckForSequenceChange;

		const FN pfCheckForSequenceChange = reinterpret_cast<FN>(U::Offsets.m_dwCheckForSequenceChange);
		XASSERT(pfCheckForSequenceChange == nullptr);

		if (pfCheckForSequenceChange)
			XASSERT(Func.Init(pfCheckForSequenceChange, &Detour) == false);
	}

	//UpdateCurrent
	{
		using namespace UpdateCurrent;

		const FN pfUpdateCurrent = reinterpret_cast<FN>(U::Offsets.m_dwUpdateCurrent);
		XASSERT(pfUpdateCurrent == nullptr);

		if (pfUpdateCurrent)
			XASSERT(Func.Init(pfUpdateCurrent, &Detour) == false);
	}
}