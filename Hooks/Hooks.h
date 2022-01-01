#pragma once

#include "BaseAnimating/BaseAnimating.h"
#include "BasePlayer/BasePlayer.h"
#include "CL_Main/CL_Main.h"
#include "Client/Client.h"
#include "ClientPrediction/ClientPrediction.h"
#include "EngineVGui/EngineVGui.h"
#include "ModelRender/ModelRender.h"
#include "ModelRenderSystem/ModelRenderSystem.h"
#include "SequenceTransitioner/SequenceTransitioner.h"
#include "TerrorClientMode/TerrorClientMode.h"
#include "TerrorGun/TerrorGun.h"
#include "TerrorPlayer/TerrorPlayer.h"
#include "VGuiPanel/VGuiPanel.h"
#include "VGuiSurface/VGuiSurface.h"
#include "WndProc/WndProc.h"

class CGlobal_Hooks
{
public:
	void Init();
};

namespace G { inline CGlobal_Hooks Hooks; }