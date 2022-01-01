#include "ESP.h"

#include "../Vars.h"

void CFeatures_ESP::Render()
{
	if (!I::EngineClient->IsInGame() || I::EngineVGui->IsGameUIVisible())
		return;

	const int nLocalIndex = I::EngineClient->GetLocalPlayer();

	C_TerrorPlayer* pLocal = I::EntityList->GetClientEntity(nLocalIndex)->As<C_TerrorPlayer*>();

	if (!pLocal)
		return;

	player_info_t pi;

	int x, y, w, h;
	for (int n = 1; n < (I::EntityList->GetMaxEntities() + 1); n++)
	{
		if (n == nLocalIndex)
			continue;

		IClientEntity* pEntity = I::EntityList->GetClientEntity(n);

		if (!pEntity || pEntity->IsDormant())
			continue;

		ClientClass* pCC = pEntity->GetClientClass();

		if (!pCC)
			continue;

		switch (pCC->m_ClassID)
		{
			case CTerrorPlayer:
			case SurvivorBot:
			{
				C_TerrorPlayer* pPlayer = pEntity->As<C_TerrorPlayer*>();

				const int nTeam = pPlayer->GetTeamNumber();

				if (pPlayer->deadflag() || !GetBounds(pPlayer, x, y, w, h) || !G::Util.IsValidTeam(nTeam))
					break;

				const bool bIsSurvivor = (nTeam == TEAM_SURVIVOR);

				const int nHealth = pPlayer->GetActualHealth();
				const int nMaxHealth = pPlayer->GetMaxHealth();

				const int nDrawX = x + (w / 2);
				int nDrawY = y + (h / 2);

				const Color clrHealth = G::Util.GetHealthColor(nHealth, nMaxHealth);
				const Color clrTeam = bIsSurvivor ? Color(15, 150, 150, 255) : Color(150, 15, 15, 255);

				if (I::EngineClient->GetPlayerInfo(n, &pi))
				{
					G::Draw.String(EFonts::ESP_NAME, nDrawX, nDrawY, { 255, 255, 255, 255 }, TXT_CENTERXY, pi.name);
					nDrawY += G::Draw.GetFontHeight(EFonts::ESP_NAME);
				}

				G::Draw.String(EFonts::ESP, nDrawX, nDrawY, clrHealth, TXT_CENTERXY, L"%i / %ihp", nHealth, nMaxHealth);
				nDrawY += G::Draw.GetFontHeight(EFonts::ESP);

				if (bIsSurvivor)
				{
					C_BaseCombatWeapon* pWeapon = pPlayer->GetActiveWeapon();

					if (pWeapon)
					{
						ClientClass* pCC = pWeapon->GetClientClass();

						if (pCC)
						{
							G::Draw.String(EFonts::ESP_WEAPON, nDrawX, nDrawY, { 204, 204, 204, 255 }, TXT_CENTERXY, pCC->m_pNetworkName);
							nDrawY += G::Draw.GetFontHeight(EFonts::ESP_WEAPON);
						}
					}
				}

				break;
			}
			case CWeaponSpawn:
			{
				C_WeaponSpawn* pSpawn = pEntity->As<C_WeaponSpawn*>();

				if (!GetBounds(pSpawn, x, y, w, h))
					break;

				const int nID = U::Math.Clamp(pSpawn->m_weaponID(), 0, 13);
				G::Draw.String(EFonts::ESP, x + (w / 2), y + (h / 2), g_aSpawnInfo[nID].m_Color, TXT_CENTERXY, g_aSpawnInfo[nID].m_szName);

				break;
			}
			default:
				break;
		}
	}
}

bool CFeatures_ESP::GetBounds(C_BaseEntity* pBaseEntity, int& x, int& y, int& w, int& h)
{
	Vector vPoints[8];
	U::Math.BuildTransformedBox(vPoints, pBaseEntity->m_vecMins(), pBaseEntity->m_vecMaxs(), pBaseEntity->RenderableToWorldTransform(), 0.0f);

	Vector flb, brt, blb, frt, frb, brb, blt, flt;
	if (G::Util.W2S(vPoints[3], flb) && G::Util.W2S(vPoints[5], brt)
		&& G::Util.W2S(vPoints[0], blb) && G::Util.W2S(vPoints[4], frt)
		&& G::Util.W2S(vPoints[2], frb) && G::Util.W2S(vPoints[1], brb)
		&& G::Util.W2S(vPoints[6], blt) && G::Util.W2S(vPoints[7], flt)
		&& G::Util.W2S(vPoints[6], blt) && G::Util.W2S(vPoints[7], flt))
	{
		const Vector vTransformed[8] = { flb, brt, blb, frt, frb, brb, blt, flt };

		float left = flb.x;
		float top = flb.y;
		float righ = flb.x;
		float bottom = flb.y;

		for (int n = 1; n < 8; n++)
		{
			if (left > vTransformed[n].x)
				left = vTransformed[n].x;

			if (top < vTransformed[n].y)
				top = vTransformed[n].y;

			if (righ < vTransformed[n].x)
				righ = vTransformed[n].x;

			if (bottom > vTransformed[n].y)
				bottom = vTransformed[n].y;
		}

		x = static_cast<int>(left);
		y = static_cast<int>(bottom);
		w = static_cast<int>(righ - left);
		h = static_cast<int>(top - bottom);

		return !(x > G::Draw.m_nScreenW || (x + w) < 0 || y > G::Draw.m_nScreenH || (y + h) < 0);
	}

	return false;
}