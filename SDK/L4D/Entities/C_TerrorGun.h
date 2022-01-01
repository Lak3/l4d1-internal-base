#pragma once

#include "C_TerrorWeapon.h"

class C_TerrorGun : public C_TerrorWeapon
{
public:
	virtual				~C_TerrorGun() = 0;

	virtual bool		IsFullyAutomatic(void) const = 0;
	virtual bool		IsSingleReload(void) const = 0;
	virtual float		GetReloadEndDuration(bool unk1) const = 0;
	virtual bool		CanBeDualWielded(void) const = 0;
	virtual bool		ViewMovementAffectsAccuracy(void) const = 0;
	virtual float		GetRateOfFire(void) const = 0;
	virtual int			GetViewmodelTracerAttachmentIndex(void) = 0;
	virtual float		GetMaxAutoAimRange(void) = 0;
	virtual float		GetMinInAirSpread(void) const = 0;
	virtual float		GetMaxMovementSpread(void) const = 0;
	virtual float		GetMinStandingSpread(void) const = 0;
	virtual float		GetMinDuckingSpread(void) const = 0;

public:
	M_NETVAR(m_fireRightSide, int, "CTerrorGun", "m_fireRightSide");
	M_NETVAR(m_isDualWielding, int, "CTerrorGun", "m_isDualWielding");
	M_NETVAR(m_hasDualWeapons, int, "CTerrorGun", "m_hasDualWeapons");
	M_NETVAR(m_reloadFromEmpty, int, "CTerrorGun", "m_reloadFromEmpty");
	M_NETVAR(m_inInitialPickup, int, "CTerrorGun", "m_inInitialPickup");
	M_NETVAR(m_needPump, int, "CTerrorGun", "m_needPump");
	M_NETVAR(m_partialReloadStage, int, "CTerrorGun", "m_partialReloadStage");

public:
	inline void UpdateSpread() {
		reinterpret_cast<void(__thiscall*)(void*)>(U::Offsets.m_dwUpdateSpread)(this);
	}
};