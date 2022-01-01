#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace SequenceTransitioner
	{
		namespace CheckForSequenceChange
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(void*, void*, CStudioHdr*, int, bool, bool);

			void __fastcall Detour(void* ecx, void* edx, CStudioHdr* hdr, int nCurSequence, bool bForceNewSequence, bool bInterpolate);
		}

		namespace UpdateCurrent
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(void*, void*, CStudioHdr*, int, float, float, float);

			void __fastcall Detour(void* ecx, void* edx, CStudioHdr* hdr, int nCurSequence, float flCurCycle, float flCurPlaybackRate, float flCurTime);
		}
		
		void Init();
	}
}