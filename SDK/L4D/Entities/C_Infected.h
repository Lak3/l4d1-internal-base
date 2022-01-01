#pragma once

#include "C_TerrorPlayer.h"

class C_NextBotCombatCharacter : public C_BaseCombatCharacter
{
public:
	virtual ~C_NextBotCombatCharacter() = 0;
};

class C_Infected : public C_NextBotCombatCharacter
{
public:
	virtual				~C_Infected() = 0;

	virtual void		UpdateBody(void) = 0;
	virtual bool		IsActivity(int unk1) const = 0;
	virtual bool		HasActivityType(unsigned int unk2) const = 0;
	virtual float		GetRunSpeed(void) const = 0;

public:
	M_NETVAR(m_flStartTime, float, "Infected", "m_flStartTime");
	M_NETVAR(m_bLooping, bool, "Infected", "m_bLooping");
	M_NETVAR(m_fFlags, int, "Infected", "m_fFlags");
	M_NETVAR(m_nWaterLevel, int, "Infected", "m_nWaterLevel");
	M_NETVAR(m_sequenceStartTime, float, "Infected", "m_sequenceStartTime");
	M_NETVAR(m_clientLookatTarget, int, "Infected", "m_clientLookatTarget");
	M_NETVAR(m_clientLeanYaw, float, "Infected", "m_clientLeanYaw");
	M_NETVAR(m_gibbedLimbs, int, "Infected", "m_gibbedLimbs");
	M_NETVAR(m_gibbedLimbForce, Vector, "Infected", "m_gibbedLimbForce");
	M_NETVAR(m_originalBody, int, "Infected", "m_originalBody");
	M_NETVAR(m_mobRush, bool, "Infected", "m_mobRush");
};

class C_Witch : public C_Infected
{
public:
	virtual ~C_Witch() = 0;

public:
	M_NETVAR(m_rage, float, "Witch", "m_rage");
};