#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace TerrorClientMode
	{
		namespace DoPostScreenSpaceEffects
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(void*, void*, const void*);

			void __fastcall Detour(void* ecx, void* edx, const void* pSetup);
		}

		namespace ApplyEntityGlowEffects
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(void*, void*, int, int, float, float, int, int, int);

			void __fastcall Detour(void* ecx, void* edx, int a3, int a4, float a5, float a6, int a7, int a8, int a9);
		}

		namespace GetViewModelFOV
		{
			inline Hook::CFunction Func;
			using FN = float(__fastcall*)(void*, void*);

			float __fastcall Detour(void* ecx, void* edx);
		}

		void Init();
	}
}