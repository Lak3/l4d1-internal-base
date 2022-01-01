#pragma once

#include "C_WeaponCSBase.h"

class C_TerrorWeapon : public C_WeaponCSBase
{
public:
	virtual ~C_TerrorWeapon() = 0;

	virtual bool IsDualWielding(void) const = 0;
	virtual bool CanPlayerMove(void) const = 0;
	virtual bool HasSecondaryMelee(void) = 0;
	virtual bool CanSecondaryMeleeInterruptReload(void) = 0;
	virtual bool CanFidget(void) = 0;
	virtual bool IsDroppedWhenHolstered(void) const = 0;
	virtual bool WantsCSItemPostFrame(void) const = 0;
	virtual void OnStunned(float unk1) = 0;
	virtual void OnPouncedUpon(void) = 0;
	virtual void OnOwnerTakeDamage(const void* unk1) = 0;
	virtual void TranslateViewmodelActivity(int unk1) const = 0;
	virtual int GetViewmodelMeleeActivity(void) = 0;
	virtual int GetLayerForViewmodelActicity(int unk1) const = 0;
	virtual bool CanExtendHelpingHand(void) const = 0;
	virtual float GetSwingForward(void) = 0;
	virtual void TrySwing(float unk1, float unk2, float unk3) = 0;
	virtual void OnHit(CGameTrace& unk1, const Vector& unk2, bool unk3) = 0;
	virtual void OnSwingStart(void) = 0;
	virtual void OnSwingEnd(bool unk1) = 0;
	virtual void DoSwing(void) = 0;
	virtual float SwingYawStart(void) const = 0;
	virtual float SwingYawEnd(void) const = 0;
	virtual void CheckQueuedReload(void) = 0;
	virtual void CheckCancelledReload(void) = 0;

public:
	M_NETVAR(m_helpingHandSuppressionTimer, void*, "CTerrorWeapon", "m_helpingHandSuppressionTimer");
	M_NETVAR(m_duration, float, "CTerrorWeapon", "m_duration");
	M_NETVAR(m_timestamp, float, "CTerrorWeapon", "m_timestamp");
	M_NETVAR(m_helpingHandTimer, void*, "CTerrorWeapon", "m_helpingHandTimer");
	M_NETVAR(m_helpingHandTargetTimer, void*, "CTerrorWeapon", "m_helpingHandTargetTimer");
	M_NETVAR(m_helpingHandState, int, "CTerrorWeapon", "m_helpingHandState");
	M_NETVAR(m_helpingHandTarget, int, "CTerrorWeapon", "m_helpingHandTarget");
	M_NETVAR(m_helpingHandExtendDuration, float, "CTerrorWeapon", "m_helpingHandExtendDuration");
	M_NETVAR(m_reloadQueuedStartTime, float, "CTerrorWeapon", "m_reloadQueuedStartTime");
	M_NETVAR(m_releasedAltFireButton, int, "CTerrorWeapon", "m_releasedAltFireButton");
	M_NETVAR(m_releasedFireButton, int, "CTerrorWeapon", "m_releasedFireButton");
	M_NETVAR(m_isHoldingAltFireButton, int, "CTerrorWeapon", "m_isHoldingAltFireButton");
	M_NETVAR(m_isHoldingFireButton, int, "CTerrorWeapon", "m_isHoldingFireButton");
	M_NETVAR(m_bPickedUpOnTransition, bool, "CTerrorWeapon", "m_bPickedUpOnTransition");
	M_NETVAR(m_iVsConsecutiveSwings, int, "CTerrorWeapon", "m_iVsConsecutiveSwings");
	M_NETVAR(m_flVsLastSwingTime, float, "CTerrorWeapon", "m_flVsLastSwingTime");
	M_NETVAR(m_attackTimer, void*, "CTerrorWeapon", "m_attackTimer");
	M_NETVAR(m_swingTimer, void*, "CTerrorWeapon", "m_swingTimer");

public:
	inline float GetCurrentSpread() {
		return *reinterpret_cast<float*>(reinterpret_cast<DWORD>(this) + 0xC74);
	}

	inline void SetCurrentSpread(const float flSpread) {
		*reinterpret_cast<float*>(reinterpret_cast<DWORD>(this) + 0xC74) = flSpread;
	}
};