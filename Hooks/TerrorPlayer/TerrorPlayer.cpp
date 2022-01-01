#include "TerrorPlayer.h"

#include "../../Features/NoSpread/NoSpread.h"

using namespace Hooks;

bool __fastcall TerrorPlayer::CreateMove::Detour(C_TerrorPlayer* pThis, void* edx, float flInputSampleTime, CUserCmd* pCmd)
{
	if (!pCmd || pCmd->command_number == 0)
		return Func.Original<FN>()(pThis, edx, flInputSampleTime, pCmd);

	if (Func.Original<FN>()(pThis, edx, flInputSampleTime, pCmd))
		I::Prediction->SetLocalViewAngles(pCmd->viewangles);

	if (pThis && pThis->IsAlive())
	{
		C_TerrorWeapon* pWeapon = pThis->GetActiveWeapon()->As<C_TerrorWeapon*>();

		if (pWeapon)
		{
			F::NoSpread.Run(pThis, pWeapon, pCmd);
		}
	}

	return false;
}

void __fastcall TerrorPlayer::UpdateClientSideAnimation::Detour(C_TerrorPlayer* pThis, void* edx)
{
	Func.Original<FN>()(pThis, edx);
}

void __fastcall TerrorPlayer::UpdateSurvivorFacialExpression::Detour(C_TerrorPlayer* pThis, void* edx)
{
	Func.Original<FN>()(pThis, edx);
}

void __fastcall TerrorPlayer::UpdateInfectedFacialExpression::Detour(C_TerrorPlayer* pThis, void* edx)
{
	Func.Original<FN>()(pThis, edx);
}

void __fastcall TerrorPlayer::AvoidPlayers::Detour(C_TerrorPlayer* pThis, void* edx, CUserCmd* pCmd)
{
	Func.Original<FN>()(pThis, edx, pCmd);
}

void __fastcall TerrorPlayer::OnWeaponFired::Detour(C_TerrorPlayer* pThis, void* edx)
{
	Func.Original<FN>()(pThis, edx);
}

void __fastcall TerrorPlayer::ClientThink::Detour(C_TerrorPlayer* pThis, void* edx)
{
	Func.Original<FN>()(pThis, edx);
}

void TerrorPlayer::Init()
{
	//CreateMove
	{
		using namespace CreateMove;

		const FN pfCreateMove = reinterpret_cast<FN>(U::Offsets.m_dwTerrorPlayerCreateMove);
		XASSERT(pfCreateMove == nullptr);

		if (pfCreateMove)
			XASSERT(Func.Init(pfCreateMove, &Detour) == false);
	}

	//UpdateClientSideAnimation
	{
		using namespace UpdateClientSideAnimation;

		const FN pfUpdateClientSideAnimation = reinterpret_cast<FN>(U::Offsets.m_dwUpdateClientSideAnimation);
		XASSERT(pfUpdateClientSideAnimation == nullptr);

		if (pfUpdateClientSideAnimation)
			XASSERT(Func.Init(pfUpdateClientSideAnimation, &Detour) == false);
	}

	//UpdateSurvivorFacialExpression
	{
		using namespace UpdateSurvivorFacialExpression;

		const FN pfUpdateSurvivorFacialExpression = reinterpret_cast<FN>(U::Offsets.m_dwUpdateSurvivorFacialExpression);
		XASSERT(pfUpdateSurvivorFacialExpression == nullptr);

		if (pfUpdateSurvivorFacialExpression)
			XASSERT(Func.Init(pfUpdateSurvivorFacialExpression, &Detour) == false);
	}

	//UpdateInfectedFacialExpression
	{
		using namespace UpdateInfectedFacialExpression;

		const FN pfUpdateInfectedFacialExpression = reinterpret_cast<FN>(U::Offsets.m_dwUpdateInfectedFacialExpression);
		XASSERT(pfUpdateInfectedFacialExpression == nullptr);

		if (pfUpdateInfectedFacialExpression)
			XASSERT(Func.Init(pfUpdateInfectedFacialExpression, &Detour) == false);
	}

	//AvoidPlayers
	{
		using namespace AvoidPlayers;

		const FN pfAvoidPlayers = reinterpret_cast<FN>(U::Offsets.m_dwAvoidPlayers);
		XASSERT(pfAvoidPlayers == nullptr);

		if (pfAvoidPlayers)
			XASSERT(Func.Init(pfAvoidPlayers, &Detour) == false);
	}

	//OnWeaponFired
	{
		using namespace OnWeaponFired;

		const FN pfOnWeaponFired = reinterpret_cast<FN>(U::Offsets.m_dwOnWeaponFired);
		XASSERT(pfOnWeaponFired == nullptr);

		if (pfOnWeaponFired)
			XASSERT(Func.Init(pfOnWeaponFired, &Detour) == false);
	}

	//ClientThink
	{
		using namespace ClientThink;

		const FN pfClientThink = reinterpret_cast<FN>(U::Offsets.m_dwClientThink);
		XASSERT(pfClientThink == nullptr);

		if (pfClientThink)
			XASSERT(Func.Init(pfClientThink, &Detour) == false);
	}
}