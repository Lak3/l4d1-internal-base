#include "TerrorGun.h"

using namespace Hooks;

void __fastcall TerrorGun::UpdateSpread::Detour(C_TerrorGun* pThis, void* edx)
{
	Func.Original<FN>()(pThis, edx);
}

void TerrorGun::Init()
{
	//UpdateSpread
	{
		using namespace UpdateSpread;

		const FN pfUpdateSpread = reinterpret_cast<FN>(U::Offsets.m_dwUpdateSpread);
		XASSERT(pfUpdateSpread == nullptr);

		if (pfUpdateSpread)
			XASSERT(Func.Init(pfUpdateSpread, &Detour) == false);
	}
}