#include "NoSpread.h"

#include "../Vars.h"

void CFeatures_NoSpread::Run(C_TerrorPlayer* pLocal, C_TerrorWeapon* pWeapon, CUserCmd* pCmd)
{
	static const auto pfSharedRandomFloat = reinterpret_cast<float(*)(const char*, float, float, int)>(U::Offsets.m_dwSharedRandomFloat);

	if (!ShouldRun(pLocal, pWeapon, pCmd))
		return;

	//Remove spread from viewangles
	{
		C_TerrorGun* pGun = pWeapon->As<C_TerrorGun*>();

		pCmd->random_seed = (MD5_PseudoRandom(pCmd->command_number) & INT_MAX);
		reinterpret_cast<void(*)(CUserCmd*)>(U::Offsets.m_dwSetPredictionRandomSeed)(pCmd);

		const float flOldSpread = pGun->GetCurrentSpread();
		pGun->UpdateSpread();
		const float flSpread = pGun->GetCurrentSpread();

		pCmd->viewangles -= {
			pfSharedRandomFloat("CTerrorGun::FireBullet HorizSpread", -flSpread, flSpread, 0),
			pfSharedRandomFloat("CTerrorGun::FireBullet VertSpread", -flSpread, flSpread, 0),
			0.0f
		};

		pGun->SetCurrentSpread(flOldSpread);

		reinterpret_cast<void(*)(CUserCmd*)>(U::Offsets.m_dwSetPredictionRandomSeed)(nullptr);
	}

	//Remove punch from viewangles
	pCmd->viewangles -= pLocal->m_vecPunchAngle();
}

bool CFeatures_NoSpread::ShouldRun(C_TerrorPlayer* pLocal, C_TerrorWeapon* pWeapon, CUserCmd* pCmd)
{
	if ((pCmd->buttons & IN_USE) || (pCmd->buttons & IN_ATTACK2) || !(pCmd->buttons & IN_ATTACK))
		return false;

	if (pLocal->m_isIncapacitated() || pLocal->m_isHangingFromLedge() || pLocal->m_isHangingFromTongue() || !pLocal->CanAttackFull())
		return false;

	ClientClass* pCC = pWeapon->GetClientClass();

	if (!pCC)
		return false;

	switch (pCC->m_ClassID)
	{
		case CSubMachinegun:
		case CAssaultRifle:
		case CSniperRifle:
		case CPistol:
			break;
		default:
			return false;
	}

	return true;
}