#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace TerrorPlayer
	{
		namespace CreateMove
		{
			inline Hook::CFunction Func;
			using FN = bool(__fastcall*)(C_TerrorPlayer*, void*, float, CUserCmd*);

			bool __fastcall Detour(C_TerrorPlayer* pThis, void* edx, float flInputSampleTime, CUserCmd* pCmd);
		}

		namespace UpdateClientSideAnimation
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(C_TerrorPlayer*, void*);

			void __fastcall Detour(C_TerrorPlayer* pThis, void* edx);
		}

		namespace UpdateSurvivorFacialExpression
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(C_TerrorPlayer*, void*);

			void __fastcall Detour(C_TerrorPlayer* pThis, void* edx);
		}

		namespace UpdateInfectedFacialExpression
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(C_TerrorPlayer*, void*);

			void __fastcall Detour(C_TerrorPlayer* pThis, void* edx);
		}

		namespace AvoidPlayers
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(C_TerrorPlayer*, void*, CUserCmd*);

			void __fastcall Detour(C_TerrorPlayer* pThis, void* edx, CUserCmd* pCmd);
		}

		namespace OnWeaponFired
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(C_TerrorPlayer*, void*);

			void __fastcall Detour(C_TerrorPlayer* pThis, void* edx);
		}

		namespace ClientThink
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(C_TerrorPlayer*, void*);

			void __fastcall Detour(C_TerrorPlayer* pThis, void* edx);
		}

		void Init();
	}
}