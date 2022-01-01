#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace TerrorGun
	{
		namespace UpdateSpread
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(C_TerrorGun*, void*);

			void __fastcall Detour(C_TerrorGun* pThis, void* edx);
		}

		void Init();
	}
}