#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace VGuiSurface
	{
		inline Hook::CTable Table;

		namespace LockCursor
		{
			using FN = void(__fastcall*)(void* ecx, void* edx);
			constexpr uint32_t Index = 60u;

			void __fastcall Detour(void* ecx, void* edx);
		}

		void Init();
	}
}