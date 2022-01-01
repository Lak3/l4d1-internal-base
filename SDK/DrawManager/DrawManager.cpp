#include "DrawManager.h"

void CGlobal_DrawManager::Init()
{
	m_Fonts[EFonts::DEBUG]         = { "Consolas",  16, FW_DONTCARE, EFontFlags::FONTFLAG_OUTLINE };
	m_Fonts[EFonts::ESP]           = { "Tahoma",    11, FW_DONTCARE, EFontFlags::FONTFLAG_OUTLINE };
	m_Fonts[EFonts::ESP_NAME]      = { "Arial",     14, FW_DONTCARE, EFontFlags::FONTFLAG_OUTLINE };
	m_Fonts[EFonts::ESP_WEAPON]    = { "Verdana",   12, FW_DONTCARE, EFontFlags::FONTFLAG_OUTLINE };
	m_Fonts[EFonts::MENU_TAHOMA]   = { "Tahoma",    12, FW_DONTCARE, EFontFlags::FONTFLAG_OUTLINE };
	m_Fonts[EFonts::MENU_CONSOLAS] = { "Consolas",  12, FW_DONTCARE, EFontFlags::FONTFLAG_OUTLINE };
	m_Fonts[EFonts::MENU_VERDANA]  = { "Verdana",   12, FW_DONTCARE, EFontFlags::FONTFLAG_OUTLINE };
	m_Fonts[EFonts::MENU_ARIAL]    = { "Arial",     12, FW_DONTCARE, EFontFlags::FONTFLAG_OUTLINE };
	m_Fonts[EFonts::MENU_TAB]      = { "Verdana",   30, FW_HEAVY   , EFontFlags::FONTFLAG_OUTLINE | EFontFlags::FONTFLAG_ANTIALIAS };

	for (std::pair<const EFonts, CFont>& f : m_Fonts)
		I::MatSystemSurface->SetFontGlyphSet(f.second.m_hFont = I::MatSystemSurface->CreateFont(), f.second.m_szName, f.second.m_nTall, f.second.m_nWeight, 0, 0, f.second.m_nFlags);
}

void CGlobal_DrawManager::String(const EFonts& font, int x, int y, const Color& clr, const short align, const char* const str, ...)
{
	va_list va_alist;
	char cbuffer[1024] = { '\0' };
	wchar_t wstr[1024] = { '\0' };

	va_start(va_alist, str);
	vsprintf_s(cbuffer, str, va_alist);
	va_end(va_alist);

	wsprintfW(wstr, L"%hs", cbuffer);

	const HFont fnt = m_Fonts[font].m_hFont;

	if (align)
	{
		int w = 0, h = 0;
		I::MatSystemSurface->GetTextSize(fnt, wstr, w, h);

		if (align & TXT_LEFT)
			x -= w;

		if (align & TXT_TOP)
			y -= h;

		if (align & TXT_CENTERX)
			x -= (w / 2);

		if (align & TXT_CENTERY)
			y -= (h / 2);
	}

	I::MatSystemSurface->DrawSetTextPos(x, y);
	I::MatSystemSurface->DrawSetTextFont(fnt);
	I::MatSystemSurface->DrawSetTextColor(clr);
	I::MatSystemSurface->DrawPrintText(wstr, wcslen(wstr));
}

void CGlobal_DrawManager::String(const EFonts& font, int x, int y, const Color& clr, const short align, const wchar_t* const str, ...)
{
	va_list va_alist;
	wchar_t wstr[1024] = { '\0' };

	va_start(va_alist, str);
	vswprintf_s(wstr, str, va_alist);
	va_end(va_alist);

	const HFont fnt = m_Fonts[font].m_hFont;

	if (align)
	{
		int w = 0, h = 0;
		I::MatSystemSurface->GetTextSize(fnt, wstr, w, h);

		if (align & TXT_LEFT)
			x -= w;

		if (align & TXT_TOP)
			y -= h;

		if (align & TXT_CENTERX)
			x -= (w / 2);

		if (align & TXT_CENTERY)
			y -= (h / 2);
	}

	I::MatSystemSurface->DrawSetTextPos(x, y);
	I::MatSystemSurface->DrawSetTextFont(fnt);
	I::MatSystemSurface->DrawSetTextColor(clr);
	I::MatSystemSurface->DrawPrintText(wstr, wcslen(wstr));
}

void CGlobal_DrawManager::Line(const int x, const int y, const int x1, const int y1, const Color& clr)
{
	I::MatSystemSurface->DrawSetColor(clr);
	I::MatSystemSurface->DrawLine(x, y, x1, y1);
}

void CGlobal_DrawManager::Rect(const int x, const int y, const int w, const int h, const Color& clr)
{
	I::MatSystemSurface->DrawSetColor(clr);
	I::MatSystemSurface->DrawFilledRect(x, y, x + w, y + h);
}

void CGlobal_DrawManager::OutlinedRect(const int x, const int y, const int w, const int h, const Color& clr)
{
	I::MatSystemSurface->DrawSetColor(clr);
	I::MatSystemSurface->DrawOutlinedRect(x, y, x + w, y + h);
}

void CGlobal_DrawManager::GradientRect(const int x, const int y, const int x1, const int y1, const Color& clrTop, const Color& clrBottom, const bool bHorizontal)
{
	I::MatSystemSurface->DrawSetColor(clrTop);
	I::MatSystemSurface->DrawFilledRectFade(x, y, x1, y1, 255u, 255u, bHorizontal);

	I::MatSystemSurface->DrawSetColor(clrBottom);
	I::MatSystemSurface->DrawFilledRectFade(x, y, x1, y1, 0u, 255u, bHorizontal);
}

void CGlobal_DrawManager::CornerRect(const int x, const int y, const int w, const int h, const int _x, const int _y, const Color color)
{
	Line(x, y, x + (w / _x), y, color);
	Line(x, y, x, y + (h / _y), color);

	Line(x + w, y, x + w - (w / _x), y, color);
	Line(x + w, y, x + w, y + (h / _y), color);

	Line(x, y + h, x + (w / _x), y + h, color);
	Line(x, y + h, x, y + h - (h / _y), color);

	Line(x + w, y + h, x + w - (w / _x), y + h, color);
	Line(x + w, y + h, x + w, y + h - (h / _y), color);
}

void CGlobal_DrawManager::OutlinedCircle(const int x, const int y, const int radius, const int segments, const Color clr)
{
	I::MatSystemSurface->DrawSetColor(clr);
	I::MatSystemSurface->DrawOutlinedCircle(x, y, radius, segments);
}

void CGlobal_DrawManager::Circle(const int x, const int y, const int radius, const int segments, const Color clr)
{
	std::vector<Vertex_t> vecVertices = { };

	const float flStep = (6.28318530718f / static_cast<float>(segments));

	for (float n = 0.0f; n < 6.28318530718f; n += flStep)
		vecVertices.push_back(Vertex_t({ (static_cast<float>(radius) * ::cos(n) + x), (static_cast<float>(radius) * ::sinf(n) + y) }, { 0.0f, 0.0f }));

	if (!vecVertices.empty())
	{
		I::MatSystemSurface->DrawSetColor(clr);
		I::MatSystemSurface->DrawTexturedPolygon(segments, vecVertices.data());
	}
}

int CGlobal_DrawManager::GetFontHeight(const EFonts& font) const
{
	return m_Fonts.at(font).m_nTall;
}

void CGlobal_DrawManager::Triangle(Vector2D* v, const Color clr)
{
	static int nTexture = I::MatSystemSurface->CreateNewTextureID(true);

	Vertex_t Vertices[3] = { { v[0] }, { v[1] }, { v[2] } };

	I::MatSystemSurface->DrawSetTexture(nTexture);
	I::MatSystemSurface->DrawSetColor(clr);
	I::MatSystemSurface->DrawTexturedPolygon(3, Vertices);
}

void CGlobal_DrawManager::Texture(const int x, const int y, const int nSize, const int nIndex)
{
	if (nIndex == -1)
		return;

	if (m_Textures.find(nIndex) != m_Textures.end())
	{
		I::MatSystemSurface->DrawSetColor({ 255u, 255u, 255u, 255u });
		I::MatSystemSurface->DrawSetTexture(m_Textures[nIndex]);
		I::MatSystemSurface->DrawTexturedRect(x, y, x + nSize, y + nSize);
	}
	else
	{
		const int nTexture = I::MatSystemSurface->CreateNewTextureID(true);

		if (I::MatSystemSurface->IsTextureIDValid(nTexture))
		{
			I::MatSystemSurface->DrawSetTextureFile(nTexture, g_szTexturePaths[nIndex], 0, true);
			m_Textures[nIndex] = nTexture;
		}
	}
}