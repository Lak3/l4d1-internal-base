#pragma once

#include "C_BaseCombatWeapon.h"

class C_WeaponCSBase : public C_BaseCombatWeapon
{
public:
	virtual				~C_WeaponCSBase() = 0;
	
	virtual bool		IsHelpingHandExtended(void) const = 0;
	virtual bool		CanPlayerTouch(C_CSPlayer* unk1) = 0;
	virtual bool		IsAttacking(void) const = 0;
	virtual void		WeaponTranslateMainActivity(int unk1) = 0;

private:
	virtual void*		GetWeaponFireActivity(int unk1, int unk2) = 0;
	virtual void*		GetWeaponReloadActivity(int unk1, int unk2) = 0;
	virtual void*		GetWeaponDeployActivity(int unk1, int unk2) = 0;

public:
	virtual bool		IsAwp(void) const = 0;
	virtual bool		CanZoom(void) const = 0;
	virtual bool		HasScope(void) const = 0;

private:
	virtual void*		CycleZoom(void) = 0;

public:
	virtual float		GetMaxSpeed(void) const = 0;
	virtual int			GetWeaponID(void) const = 0;
	virtual bool		IsSilenced(void) const = 0;
	virtual void		SetWeaponModelIndex(const char* pName) = 0;
	virtual void		EjectBrass(void) = 0;
	virtual void		ClearCrosshair(void) = 0;
	virtual void		ResetCrosshair(void) = 0;

private:
	virtual void*		HasWeaponTimerHud(void) = 0;
	virtual void*		GetWeaponTimerHudPercent(void) = 0;
	virtual void*		GetWeaponTimerHudTextureNames(const char** unk1, const char** unk2) = 0;

public:
	virtual int			GetMuzzleAttachment(void) = 0;
	virtual int			GetShellAttachment(void) = 0;
	virtual bool		HideViewModelWhenZoomed(void) = 0;
	virtual int			GetMuzzleFlashStyle(void) = 0;
	virtual void		UpdateShieldState(void) = 0;
	virtual bool		HasSecondaryAttack(void) = 0;
	virtual int         GetDeployActivity(void) = 0;
	virtual bool		DefaultPistolReload() = 0;
	virtual bool		DeployResetsAttackTime(void) = 0;
	virtual bool		CanBeDropped(void) const = 0;

public:
	M_NETVAR(m_iExtraPrimaryAmmo, int, "CWeaponCSBase", "m_iExtraPrimaryAmmo");
};