#pragma once

#include "../../SDK/SDK.h"

namespace Hooks
{
	namespace BaseAnimating
	{
		namespace BuildTransformations
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(C_BaseAnimating*, void*, CStudioHdr*, void*, void*, const matrix3x4_t&, int, void*);

			void __fastcall Detour(C_BaseAnimating* pThis, void* edx, CStudioHdr* hdr, void* pos, void* q, const matrix3x4_t& cameraTransform, int boneMask, void* boneComputed);
		}

		namespace StandardBlendingRules
		{
			inline Hook::CFunction Func;
			using FN = void(__fastcall*)(C_BaseAnimating*, void*, CStudioHdr*, Vector[], void*, float, int);

			void __fastcall Detour(C_BaseAnimating* pThis, void* edx, CStudioHdr* hdr, Vector pos[], void* q, float currentTime, int boneMask);
		}

		namespace GetClientModelRenderable
		{
			inline Hook::CFunction Func;
			using FN = IClientModelRenderable* (__fastcall*)(C_BaseAnimating*, void*);

			IClientModelRenderable* __fastcall Detour(C_BaseAnimating* pThis, void* edx);
		}

		void Init();
	}
}