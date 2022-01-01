#pragma once

#include "ClientEntityList.h"

class C_BasePlayer;
class C_BaseEntity;

class CMoveData
{
private:
	char __pad00[184]; //TODO: Confirm size
};

class IGameMovement
{
public:
	virtual					~IGameMovement(void) {}

	virtual void			ProcessMovement(C_BasePlayer* pPlayer, CMoveData* pMove) = 0;
	virtual void			Reset(void) = 0;
	virtual void			StartTrackPredictionErrors(C_BasePlayer* pPlayer) = 0;
	virtual void			FinishTrackPredictionErrors(C_BasePlayer* pPlayer) = 0;
	virtual void			DiffPrint(char const* fmt, ...) = 0;
	virtual Vector const&	GetPlayerMins(bool ducked) const = 0;
	virtual Vector const&	GetPlayerMaxs(bool ducked) const = 0;
	virtual Vector const&	GetPlayerViewOffset(bool ducked) const = 0;
	virtual bool			IsMovingPlayerStuck(void) const = 0;
	virtual C_BasePlayer*	GetMovingPlayer(void) const = 0;
	virtual void			UnblockPusher(C_BasePlayer* pPlayer, C_BaseEntity* pPusher) = 0;
	virtual void			SetupMovementBounds(CMoveData* pMove) = 0;
};

namespace I { inline IGameMovement* GameMovement = nullptr; }