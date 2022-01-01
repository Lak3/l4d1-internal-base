#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace VGuiPanel
	{
		inline Hook::CTable Table;

		namespace PaintTraverse
		{
			using FN = void(__fastcall*)(void*, void*, VPANEL, bool, bool);
			constexpr uint32_t Index = 41u;

			void __fastcall Detour(void* ecx, void* edx, VPANEL vguiPanel, bool forceRepaint, bool allowForce);
		}

		void Init();
	}
}