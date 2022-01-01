#pragma once

#include "DrawManager/DrawManager.h"

struct WeaponSpawnInfo_t {
	const wchar_t* m_szName;
	const Color m_Color;
};

static const WeaponSpawnInfo_t g_aSpawnInfo[] =
{
	{ L"unknown", { 255u, 255u, 255u, 255u } },
	{ L"pistol", { 240u, 240u, 240u, 255u } },
	{ L"uzi", { 240u, 240u, 240u, 255u } },
	{ L"pump shotgun", { 240u, 240u, 240u, 255u } },
	{ L"auto shotgun", { 240u, 240u, 240u, 255u } },
	{ L"assault rifle", { 240u, 240u, 240u, 255u } },
	{ L"sniper rifle", { 240u, 240u, 240u, 255u } },
	{ L"unknown", { 255u, 255u, 255u, 255u } },
	{ L"firstaid", { 153u, 255u, 153u, 255u } },
	{ L"molotov", { 255u, 255u, 255u, 255u } },
	{ L"pipebomb", { 255u, 255u, 255u, 255u } },
	{ L"unknown", { 255u, 255u, 255u, 255u } },
	{ L"pills", { 153u, 255u, 153u, 255u } },
	{ L"unknown", { 255u, 255u, 255u, 255u } }
};