#pragma once

#include "../GameUtil/GameUtil.h"

#define TXT_DEFAULT		(1 << 0)
#define TXT_LEFT		(1 << 1)
#define TXT_TOP			(1 << 2)
#define TXT_CENTERX		(1 << 3)
#define TXT_CENTERY		(1 << 4)
#define TXT_CENTERXY	TXT_CENTERX | TXT_CENTERY

enum class EFonts {
	DEBUG,
	ESP,
	ESP_NAME,
	ESP_WEAPON,
	MENU_TAHOMA,
	MENU_CONSOLAS,
	MENU_VERDANA,
	MENU_ARIAL,
	MENU_TAB,
	FONT_LAST
};

class CGlobal_DrawManager
{
private:
	class CFont {
	public:
		const char* m_szName;
		int m_nTall;
		int m_nWeight;
		int m_nFlags;
		HFont m_hFont;
	};

public:
	void Init();

public:
	void String(const EFonts& font, int x, int y, const Color& clr, const short align, const char* const str, ...);
	void String(const EFonts& font, int x, int y, const Color& clr, const short align, const wchar_t* const str, ...);

	void Line(const int x, const int y, const int x1, const int y1, const Color& clr);
	void Rect(const int x, const int y, const int w, const int h, const Color& clr);
	void OutlinedRect(const int x, const int y, const int w, const int h, const Color& clr);
	void GradientRect(const int x, const int y, const int x1, const int y1, const Color& clrTop, const Color& clrBottom, const bool bHorizontal);
	void CornerRect(const int x, const int y, const int w, const int h, const int _x, const int _y, const Color color);
	void OutlinedCircle(const int x, const int y, const int radius, const int segments, const Color clr);
	void Circle(const int x, const int y, const int radius, const int segments, const Color clr);
	void Triangle(Vector2D* v, const Color clr);
	void Texture(const int x, const int y, const int nSize, const int nIndex);

public:
	int GetFontHeight(const EFonts& font) const;

private:
	std::map<EFonts, CFont> m_Fonts = { };
	std::map<int, int> m_Textures = { };

public:
	int m_nScreenW = 0;
	int m_nScreenH = 0;
};

namespace G { inline CGlobal_DrawManager Draw; }

static const char* const g_szTexturePaths[] = {
	"vgui/select_bill.vtf",
	"vgui/select_zoey.vtf",
	"vgui/select_francis.vtf",
	"vgui/select_louis.vtf",

	"vgui/pz_panel_smoker.vtf", //4
	"vgui/pz_panel_boomer.vtf",
	"vgui/pz_panel_hunter.vtf",
	"vgui/pz_panel_hulk.vtf",

	"vgui/achievements/l4d_achievement_kill_tank_solo.vtf", //8
	"vgui/achievements/l4d_achievement_dont_awaken_witch.vtf",

	"vgui/terror/medkit_icon_lrg.vtf", //10
	"vgui/terror/molotov_icon_lrg.vtf",
	"vgui/terror/painkillers_icon_lrg.vtf",
	"vgui/terror/pipebomb_icon_lrg.vtf"
};