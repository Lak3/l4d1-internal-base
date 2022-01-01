#include "ClientPrediction.h"

using namespace Hooks;

void __fastcall ClientPrediction::RunCommand::Detour(void* ecx, void* edx, C_BasePlayer* player, CUserCmd* ucmd, IMoveHelper* moveHelper)
{
	if (!I::MoveHelper && moveHelper)
		I::MoveHelper = moveHelper;

	Table.Original<FN>(Index)(ecx, edx, player, ucmd, moveHelper);
}

void ClientPrediction::Init()
{
	XASSERT(Table.Init(I::Prediction) == false);
	XASSERT(Table.Hook(&RunCommand::Detour, RunCommand::Index) == false);
}