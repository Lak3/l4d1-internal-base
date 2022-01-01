#include "BasePlayer.h"

#include "../../Features/Vars.h"

using namespace Hooks;

void __fastcall BasePlayer::CalcPlayerView::Detour(C_BasePlayer* pThis, void* edx, Vector& eyeOrigin, Vector& eyeAngles, float& fov)
{
	if (pThis)
	{
		//Remove visual recoil

		const Vector vOldPunch = pThis->m_vecPunchAngle();

		pThis->m_vecPunchAngle().Init();
		Func.Original<FN>()(pThis, edx, eyeOrigin, eyeAngles, fov);
		pThis->m_vecPunchAngle() = vOldPunch;
	}
	else
	{
		Func.Original<FN>()(pThis, edx, eyeOrigin, eyeAngles, fov);
	}
}

bool __fastcall BasePlayer::CreateMove::Detour(C_BasePlayer* pThis, void* edx, float flInputSampleTime, CUserCmd* pCmd)
{
	return Func.Original<FN>()(pThis, edx, flInputSampleTime, pCmd);
}

void BasePlayer::Init()
{
	//CalcPlayerView
	{
		using namespace CalcPlayerView;

		const FN pfCalcPlayerView = reinterpret_cast<FN>(U::Offsets.m_dwCalcPlayerView);
		XASSERT(pfCalcPlayerView == nullptr);

		if (pfCalcPlayerView)
			XASSERT(Func.Init(pfCalcPlayerView, &Detour) == false);
	}

	//CreateMove
	{
		using namespace CreateMove;

		const FN pfBasePlayerCreateMove = reinterpret_cast<FN>(U::Offsets.m_dwBasePlayerCreateMove);
		XASSERT(pfBasePlayerCreateMove == nullptr);

		if (pfBasePlayerCreateMove)
			XASSERT(Func.Init(pfBasePlayerCreateMove, &Detour) == false);
	}
}