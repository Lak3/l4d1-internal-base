#pragma once

#include "C_TerrorGun.h"

/*
// Projectiles
*/
class C_BaseGrenade : public C_BaseCombatCharacter
{
public:
	virtual				~C_BaseGrenade() = 0;

	virtual void		Explode(trace_t* pTrace, int bitsDamageType) = 0;
	virtual void		BounceTouch(C_BaseEntity* pOther) = 0;
	virtual void		Detonate(void) = 0;
	virtual Vector		GetBlastForce() = 0;
	virtual void		BounceSound(void) = 0;
	virtual void		Event_Killed(const CTakeDamageInfo& info) = 0;
	virtual float		GetShakeAmplitude(void) = 0;
	virtual float		GetShakeRadius(void) = 0;
	virtual float		GetDamage() = 0;
	virtual float		GetDamageRadius() = 0;
	virtual void		SetDamage(float flDamage) = 0;
	virtual void		SetDamageRadius(float flDamageRadius) = 0;

private:
	virtual void*		NetworkStateChanged_m_vecVelocity(void) = 0;
	virtual void*		NetworkStateChanged_m_vecVelocity(void* unk1) = 0;
	virtual void*		NetworkStateChanged_m_fFlags(void) = 0;
	virtual void*		NetworkStateChanged_m_fFlags(void* unk1) = 0;

public:
	M_NETVAR(m_flDamage, float, "CBaseGrenade", "m_flDamage");
	M_NETVAR(m_DmgRadius, float, "CBaseGrenade", "m_DmgRadius");
	M_NETVAR(m_bIsLive, bool, "CBaseGrenade", "m_bIsLive");
	M_NETVAR(m_hThrower, int, "CBaseGrenade", "m_hThrower");
	M_NETVAR(m_vecVelocity, Vector, "CBaseGrenade", "m_vecVelocity");
	M_NETVAR(m_fFlags, int, "CBaseGrenade", "m_fFlags");
};

class C_BaseCSGrenadeProjectile : public C_BaseGrenade
{
public:
	virtual ~C_BaseCSGrenadeProjectile() = 0;

public:
	M_NETVAR(m_vInitialVelocity, Vector, "CBaseCSGrenadeProjectile", "m_vInitialVelocity");
};

class C_PipeBombProjectile : public C_BaseCSGrenadeProjectile
{
public:
	virtual ~C_PipeBombProjectile() = 0;
};

class C_MolotovProjectile : public C_BaseCSGrenadeProjectile
{
public:
	virtual ~C_MolotovProjectile() = 0;
};

/*
// Weapons
*/
class C_BaseCSGrenade : public C_TerrorWeapon
{
public:
	virtual			~C_BaseCSGrenade() = 0;

private:
	virtual void*	GetGrenadePrimeActivity(int unk1) = 0;
	virtual void*	GetGrenadeThrowActivity(int unk1) = 0;

public:
	virtual void	StartGrenadeThrow() = 0;
	virtual void	ThrowGrenade() = 0;
	virtual void	DropGrenade() = 0;

public:
	M_NETVAR(m_bRedraw, bool, "CBaseCSGrenade", "m_bRedraw");
	M_NETVAR(m_bPinPulled, bool, "CBaseCSGrenade", "m_bPinPulled");
	M_NETVAR(m_fThrowTime, float, "CBaseCSGrenade", "m_fThrowTime");
	M_NETVAR(m_isGoingToRoll, int, "CBaseCSGrenade", "m_isGoingToRoll");
};

class C_PipeBomb : public C_BaseCSGrenade
{
public:
	virtual ~C_PipeBomb() = 0;
};

class C_Molotov : public C_BaseCSGrenade
{
public:
	virtual			~C_Molotov() = 0;

	virtual void	UpdateParticles(void) = 0;
};