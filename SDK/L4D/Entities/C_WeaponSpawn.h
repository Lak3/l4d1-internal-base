#pragma once

#include "C_PipeBomb.h"

class C_WeaponSpawn : public C_BaseAnimating
{
public:
	virtual			~C_WeaponSpawn() = 0;

	virtual int		GetWeaponID(void) const = 0;

public:
	M_NETVAR(m_weaponID, int, "CWeaponSpawn", "m_weaponID");
};

class C_WeaponAmmoSpawn : public C_WeaponSpawn
{
public:
	virtual		~C_WeaponAmmoSpawn() = 0;
};