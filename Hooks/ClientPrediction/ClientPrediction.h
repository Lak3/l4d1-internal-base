#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace ClientPrediction
	{
		inline Hook::CTable Table;

		namespace RunCommand
		{
			using FN = void(__fastcall*)(void*, void*, C_BasePlayer*, CUserCmd*, IMoveHelper*);
			constexpr uint32_t Index = 18u;

			void __fastcall Detour(void* ecx, void* edx, C_BasePlayer* player, CUserCmd* ucmd, IMoveHelper* moveHelper);
		}

		void Init();
	}
}