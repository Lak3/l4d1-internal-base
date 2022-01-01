#include "Offsets.h"

void CUtil_Offsets::Init()
{
	m_dwStartDrawing = U::Pattern.Find("vguimatsurface.dll", "55 8B EC 83 E4 C0 64 A1 ? ? ? ? 6A FF 68 ? ? ? ? 50 64 89 25 ? ? ? ? 83 EC 6C 80 3D ? ? ? ? ? 56 57 8B F1 75 57");
	XASSERT(m_dwStartDrawing == 0x0);

	m_dwFinishDrawing = U::Pattern.Find("vguimatsurface.dll", "6A FF 68 ? ? ? ? 64 A1 ? ? ? ? 50 64 89 25 ? ? ? ? 51 6A 00 E8 ? ? ? ? A1 ? ? ? ? 83 C4 04 50 8D 4C 24 04 E8 ? ? ? ? 8B 0C 24 8B 11 8B 42 50 6A 01 C7 44 24 ? ? ? ? ?");
	XASSERT(m_dwFinishDrawing == 0x0);

	m_dwTerrorPlayerCreateMove = U::Pattern.Find("client.dll", "83 EC 48 D9 44 24 4C 53 55 8B 6C 24 58 56 55 51 D9 1C 24 8B F1 E8 ? ? ? ? 8B 15 ? ? ? ? 8A D8 8B 86 ? ? ? ? 83 F8 FF 88 5C 24 5C 74 24");
	XASSERT(m_dwTerrorPlayerCreateMove == 0x0);

	m_dwBasePlayerCreateMove = U::Pattern.Find("client.dll", "56 8B F1 8B 86 ? ? ? ? 83 F8 FF 57 8B 7C 24 10 74 7E");
	XASSERT(m_dwBasePlayerCreateMove == 0x0);

	m_dwCalcPlayerView = U::Pattern.Find("client.dll", "83 EC 18 53 56 8B F1 8B 0D ? ? ? ? 8B 01 8B 50 38 57 FF D2 84 C0 75 0D");
	XASSERT(m_dwCalcPlayerView == 0x0);

	m_dwSharedRandomFloat = U::Pattern.Find("client.dll", "83 EC 08 A1 ? ? ? ? 53 56 57 8B 7C 24 24 8D 4C 24 24 51 89 7C 24 14 89 44 24 10 E8 ? ? ? ?");
	XASSERT(m_dwSharedRandomFloat == 0x0);

	m_dwSetPredictionRandomSeed = U::Pattern.Find("client.dll", "8B 44 24 04 85 C0 75 0B");
	XASSERT(m_dwSetPredictionRandomSeed == 0x0);

	m_dwUpdateSpread = U::Pattern.Find("client.dll", "83 EC 0C 53 56 57 8B F9 E8 ? ? ? ? 8B CF 8B D8 E8 ? ? ? ? 8B F0 85 F6 75 19");
	XASSERT(m_dwUpdateSpread == 0x0);

	m_dwCheckForSequenceChange = U::Pattern.Find("client.dll", "53 8B 5C 24 08 85 DB 56 8B F1 0F 84 ? ? ? ? 83 7E 0C 00 75 10 6A 00 E8 ? ? ? ? 8B 0E 6A 00 E8 ? ? ? ? 8B 46 0C D9 EE 8B 0E 8D 04 C0 D8 5C 81 DC 57 8D 7C 81 DC DF E0 F6 C4 44 0F 8B ? ? ? ? 55 8B 6C 24 18 39 6F 0C 75 07 80 7C 24 ? ? 74 77");
	XASSERT(m_dwCheckForSequenceChange == 0x0);

	m_dwUpdateCurrent = U::Pattern.Find("client.dll", "83 7C 24 ? ? 56 8B F1 0F 84 ? ? ? ? 83 7E 0C 00 75 10 6A 00 E8 ? ? ? ? 8B 0E 6A 00 E8 ? ? ? ? 8B 46 0C 8B 0E 8B 54 24 0C 57 8D 04 C0 8D 7C 81 DC 52");
	XASSERT(m_dwUpdateCurrent == 0x0);

	m_dwBuildTransFormations = U::Pattern.Find("client.dll", "55 8B EC 83 E4 F0 81 EC ? ? ? ? 80 3D ? ? ? ? ? 53 56 57 8B F1 B8 ? ? ? ? 74 05");
	XASSERT(m_dwBuildTransFormations == 0x0);

	m_dwStandardBlendingRules = U::Pattern.Find("client.dll", "B8 ? ? ? ? E8 ? ? ? ? 56 57 8B BC 24 ? ? ? ? 85 FF 8B F1 0F 84 ? ? ? ?");
	XASSERT(m_dwStandardBlendingRules == 0x0);

	m_dwUpdateClientSideAnimation = U::Pattern.Find("client.dll", "83 EC 60 56 8B F1 8B 06 8B 90 ? ? ? ? FF D2 83 F8 02 0F 8C ? ? ? ?");
	XASSERT(m_dwUpdateClientSideAnimation == 0x0);

	m_dwUpdateSurvivorFacialExpression = U::Pattern.Find("client.dll", "83 EC 14 56 8B F1 80 BE ? ? ? ? ? 74 09");
	XASSERT(m_dwUpdateSurvivorFacialExpression == 0x0);

	m_dwUpdateInfectedFacialExpression = U::Pattern.Find("client.dll", "56 8B F1 8B 06 8B 90 ? ? ? ? FF D2 83 F8 03 0F 85 ? ? ? ?");
	XASSERT(m_dwUpdateInfectedFacialExpression == 0x0);

	m_dwDisableJiggleBones = U::Pattern.Find("client.dll", "56 57 8B F9 8B B7 ? ? ? ? 85 F6 C6 87 ? ? ? ? ? 74 43");
	XASSERT(m_dwDisableJiggleBones == 0x0);

	m_dwAvoidPlayers = U::Pattern.Find("client.dll", "81 EC ? ? ? ? 57 8B F9 80 BF ? ? ? ? ? 0F 85 ? ? ? ?");
	XASSERT(m_dwAvoidPlayers == 0x0);

	m_dwOnWeaponFired = U::Pattern.Find("client.dll", "51 D9 EE 56 57 8B F9 D8 9F ? ? ? ? DF E0 F6 C4 05 7B 30");
	XASSERT(m_dwOnWeaponFired == 0x0);

	m_dwClientThink = U::Pattern.Find("client.dll", "83 EC 24 55 56 57 8B F9 E8 ? ? ? ? 80 BF ? ? ? ? ? 75 11");
	XASSERT(m_dwClientThink == 0x0);

	m_dwDoPostScreenSpaceEffects = U::Pattern.Find("client.dll", "A1 ? ? ? ? 83 EC 14 83 78 30 00 57 8B F9 0F 85 ? ? ? ?");
	XASSERT(m_dwDoPostScreenSpaceEffects == 0x0);

	m_dwDrawModels = U::Pattern.Find("client.dll", "55 8B EC 83 EC 38 53 8B 5D 0C 85 DB 56 57 8B F9 89 7D F4 0F 84 ? ? ? ?");
	XASSERT(m_dwDrawModels == 0x0);

	m_dwGetClientModelRenderable = U::Pattern.Find("client.dll", "56 8B F1 80 BE ? ? ? ? ? 74 53");
	XASSERT(m_dwGetClientModelRenderable == 0x0);

	m_dwApplyEntityGlowEffects = U::Pattern.Find("client.dll", "81 EC ? ? ? ? 55 56 57 8B F9 6A FF 89 7C 24 20 E8 ? ? ? ? 8B E8 33 F6 83 C4 04 3B EE 89 6C 24 10 0F 84 ? ? ? ?");
	XASSERT(m_dwApplyEntityGlowEffects == 0x0);

	m_dwGetViewmodelFov = U::Pattern.Find("client.dll", "83 EC 24 56 E8 ? ? ? ? 8B 0D ? ? ? ? 8B F0 8B 01 8B 90 ? ? ? ? 6A 00 FF D2 50 56 68 ? ? ? ? 68 ? ? ? ? 8D 4C 24 1C E8 ? ? ? ? 6A FF E8 ? ? ? ? 8B F0 83 C4 04 85 F6 0F 84 ? ? ? ?");
	XASSERT(m_dwGetViewmodelFov == 0x0);

	m_dwCLMove = U::Pattern.Find("engine.dll", "83 EC 24 56 E8 ? ? ? ? 8B F0 83 7E 68 02 0F 8C ? ? ? ?");
	XASSERT(m_dwCLMove == 0x0);
}