#pragma once

#include "../Pattern/Pattern.h"

class CUtil_Offsets
{
public:
	void Init();

public:
	DWORD m_dwStartDrawing = 0x0;
	DWORD m_dwFinishDrawing = 0x0;
	DWORD m_dwTerrorPlayerCreateMove = 0x0;
	DWORD m_dwBasePlayerCreateMove = 0x0;
	DWORD m_dwCalcPlayerView = 0x0;
	DWORD m_dwSharedRandomFloat = 0x0;
	DWORD m_dwSetPredictionRandomSeed = 0x0;
	DWORD m_dwUpdateSpread = 0x0;
	DWORD m_dwCheckForSequenceChange = 0x0;
	DWORD m_dwUpdateCurrent = 0x0;
	DWORD m_dwBuildTransFormations = 0x0;
	DWORD m_dwStandardBlendingRules = 0x0;
	DWORD m_dwUpdateClientSideAnimation = 0x0;
	DWORD m_dwUpdateSurvivorFacialExpression = 0x0;
	DWORD m_dwUpdateInfectedFacialExpression = 0x0;
	DWORD m_dwDisableJiggleBones = 0x0;
	DWORD m_dwAvoidPlayers = 0x0;
	DWORD m_dwOnWeaponFired = 0x0;
	DWORD m_dwClientThink = 0x0;
	DWORD m_dwDoPostScreenSpaceEffects = 0x0;
	DWORD m_dwDrawModels = 0x0;
	DWORD m_dwGetClientModelRenderable = 0x0;
	DWORD m_dwApplyEntityGlowEffects = 0x0;
	DWORD m_dwGetViewmodelFov = 0x0;
	DWORD m_dwCLMove = 0x0;
};

namespace U { inline CUtil_Offsets Offsets; }