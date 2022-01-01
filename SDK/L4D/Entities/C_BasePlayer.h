#pragma once

#include "C_BaseCombatCharacter.h"

class IRagdoll;
class CHintSystem;
class C_BaseViewModel;

enum {
	TEAM_SURVIVOR = 2,
	TEAM_INFECTED
};

class C_BasePlayer : public C_BaseCombatCharacter
{
public:
	enum eObserverInterpState {
		OBSERVER_INTERP_NONE,
		OBSERVER_INTERP_TRAVELING,
		OBSERVER_INTERP_SETTLING
	};

public:
	virtual						~C_BasePlayer() = 0;

	virtual void				SharedSpawn() = 0;
	virtual void				OnBecomeLocalPlayer(void) = 0;
	virtual void				CalcView(Vector& eyeOrigin, Vector& eyeAngles, float& zNear, float& zFar, float& fov) = 0;
	virtual void				CalcViewModelView(const Vector& eyeOrigin, const Vector& eyeAngles) = 0;
	virtual float				CalcRoll(const Vector& angles, const Vector& velocity, float rollangle, float rollspeed) = 0;
	virtual bool				IsInThirdPersonView(void) const = 0;
	virtual void				SetPlayerUnderwater(bool state) = 0;
	virtual void				PlayWadeSound(void) = 0;
	virtual Vector				Weapon_ShootPosition() = 0;
	virtual void				Weapon_DropPrimary(void) = 0;
	virtual Vector				GetAutoaimVector(float flScale) = 0;
	virtual bool				CreateMove(float flInputSampleTime, CUserCmd* pCmd) = 0;
	virtual void				AvoidPhysicsProps(CUserCmd* pCmd) = 0;
	virtual void				PlayerUse(void) = 0;
	virtual C_BaseEntity*		GetUseTarget(void) = 0;
	virtual C_BaseEntity*		GetPotentialUseTarget(void) = 0;
	virtual C_BaseEntity*		FindUseEntity(float unk1, float unk2, bool* unk3) = 0;
	virtual bool				IsUseableEntity(C_BaseEntity* pEntity, unsigned int requiredCaps) = 0;
	virtual void				OverrideMouseInput(float* unk1, float* unk2) = 0;
	virtual void				OverrideJoystickInput(float* unk1, float* unk2) = 0;
	virtual int					GetObserverMode() const = 0;
	virtual C_BaseEntity*		GetObserverTarget() const = 0;
	virtual bool				IsBot(void) const = 0;
	virtual IRagdoll*			GetRepresentativeRagdoll() const = 0;
	virtual void				TeamChange(int iNewTeam) = 0;
	virtual const char*			GetFlashlightTextureName(void) const = 0;
	virtual float				GetFlashlightFOV(void) const = 0;
	virtual float				GetFlashlightFarZ(void) const = 0;
	virtual float				GetFlashlightLinearAtten(void) const = 0;
	virtual bool				CastsFlashlightShadows(void) const = 0;
	virtual void				GetFlashlightOffset(const Vector& vecForward, const Vector& vecRight, const Vector& vecUp, Vector* pVecOffset) const = 0;
	virtual bool				IsAllowedToSwitchWeapons(void) = 0;
	virtual C_BaseCombatWeapon* GetActiveWeaponForSelection(void) = 0;
	virtual C_BaseAnimating*	GetRenderedWeaponModel() = 0;
	virtual bool				IsOverridingViewmodel(void) = 0;
	virtual int					DrawOverriddenViewmodel(C_BaseViewModel* pViewmodel, int flags, const RenderableInstance_t& instance) = 0;
	virtual float				GetDefaultAnimSpeed(void) = 0;
	virtual bool				CanSetSoundMixer(void) = 0;
	virtual unsigned int		PlayerSolidMask(bool unk1) const = 0;
	virtual void				PreThink(void) = 0;
	virtual void				PostThink(void) = 0;
	virtual void				ItemPreFrame(void) = 0;
	virtual void				ItemPostFrame(void) = 0;
	virtual void				AbortReload(void) = 0;
	virtual void				SelectLastItem(void) = 0;
	virtual void				Weapon_SetLast(C_BaseCombatWeapon* pWeapon) = 0;
	virtual bool				Weapon_ShouldSetLast(C_BaseCombatWeapon* pOldWeapon, C_BaseCombatWeapon* pNewWeapon) = 0;
	virtual bool				Weapon_ShouldSelectItem(C_BaseCombatWeapon* pWeapon) = 0;
	virtual C_BaseCombatWeapon* GetLastWeapon(void) = 0;
	virtual void 				SelectItem(const char* pstr, int iSubType = 0) = 0;
	virtual void				SelectItem(C_BaseCombatWeapon* unk1) = 0;
	virtual void				UpdateClientData(void) = 0;
	virtual float				GetFOV(void) const = 0;
	virtual int					GetDefaultFOV(void) const = 0;
	virtual bool				IsZoomed(void) = 0;
	virtual void				ViewPunch(const Vector& angleOffset) = 0;
	virtual void				OverrideView(void* pSetup) = 0;
	virtual const char*			GetCharacterDisplayName() = 0;
	virtual const Vector		GetPlayerMins(void) const = 0;
	virtual const Vector		GetPlayerMaxs(void) const = 0;
	virtual void				SetVehicleRole(int nRole) = 0;
	virtual void				SetAnimation(int playerAnim) = 0; //PLAYER_ANIM
	virtual float				GetMinFOV() const = 0;
	virtual void				PlayPlayerJingle(void) = 0;
	virtual void				UpdateStepSound(void* psurface, const Vector& vecOrigin, const Vector& vecVelocity) = 0;
	virtual void				PlayStepSound(Vector& vecOrigin, void* psurface, float fvol, bool force) = 0;
	virtual void*				GetFootstepSurface(const Vector& origin, const char* surfaceName) = 0;
	virtual void				GetStepSoundVelocities(float* velwalk, float* velrun) = 0;
	virtual void				SetStepSoundTime(int iStepSoundTime, bool bWalking) = 0; //stepsoundtimes_t
	virtual void				ExitLadder() = 0;
	virtual CHintSystem*		Hints(void) = 0;
	virtual	IMaterial*			GetHeadLabelMaterial(void) = 0;
	virtual void				CalcObserverView(Vector& eyeOrigin, Vector& eyeAngles, float& fov) = 0;
	virtual Vector				GetChaseCamViewOffset(C_BaseEntity* target) = 0;
	virtual void				CalcChaseCamView(Vector& eyeOrigin, Vector& eyeAngles, float& fov) = 0;
	virtual void				CalcInEyeCamView(Vector& eyeOrigin, Vector& eyeAngles, float& fov) = 0;
	virtual void				CalcDeathCamView(Vector& eyeOrigin, Vector& eyeAngles, float& fov) = 0;
	virtual void				CalcRoamingView(Vector& eyeOrigin, Vector& eyeAngles, float& fov) = 0;
	virtual void				SetLocalViewAngles(const Vector& viewAngles) = 0;
	virtual void				SetViewAngles(const Vector& ang) = 0;
	virtual bool				IsDucked(void) const = 0;
	virtual bool				IsDucking(void) const = 0;
	virtual void				SetDucked(bool unk1) = 0;
	virtual void				SetDucking(bool unk1) = 0;
	virtual float				GetFallVelocity(void) = 0;

public:
	M_NETVAR(m_Local, void*, "CBasePlayer", "m_Local");
	M_NETVAR(m_chAreaBits, void*, "CBasePlayer", "m_chAreaBits");
	M_NETVAR(m_chAreaPortalBits, void*, "CBasePlayer", "m_chAreaPortalBits");
	M_NETVAR(m_iHideHUD, int, "CBasePlayer", "m_iHideHUD");
	M_NETVAR(m_flFOVRate, float, "CBasePlayer", "m_flFOVRate");
	M_NETVAR(m_bDucked, bool, "CBasePlayer", "m_bDucked");
	M_NETVAR(m_bDucking, bool, "CBasePlayer", "m_bDucking");
	M_NETVAR(m_bInDuckJump, bool, "CBasePlayer", "m_bInDuckJump");
	M_NETVAR(m_nDuckTimeMsecs, int, "CBasePlayer", "m_nDuckTimeMsecs");
	M_NETVAR(m_nDuckJumpTimeMsecs, int, "CBasePlayer", "m_nDuckJumpTimeMsecs");
	M_NETVAR(m_nJumpTimeMsecs, int, "CBasePlayer", "m_nJumpTimeMsecs");
	M_NETVAR(m_flFallVelocity, float, "CBasePlayer", "m_flFallVelocity");
	M_NETVAR(m_vecPunchAngle, Vector, "CBasePlayer", "m_vecPunchAngle");
	M_NETVAR(m_vecPunchAngleVel, Vector, "CBasePlayer", "m_vecPunchAngleVel");
	M_NETVAR(m_bDrawViewmodel, bool, "CBasePlayer", "m_bDrawViewmodel");
	M_NETVAR(m_bWearingSuit, bool, "CBasePlayer", "m_bWearingSuit");
	M_NETVAR(m_bPoisoned, bool, "CBasePlayer", "m_bPoisoned");
	M_NETVAR(m_flStepSize, float, "CBasePlayer", "m_flStepSize");
	M_NETVAR(m_bAllowAutoMovement, bool, "CBasePlayer", "m_bAllowAutoMovement");
	M_NETVAR(m_bAutoAimTarget, bool, "CBasePlayer", "m_bAutoAimTarget");
	M_NETVAR(m_skybox3d_scale, int, "CBasePlayer", "m_skybox3d.scale");
	M_NETVAR(m_skybox3d_origin, Vector, "CBasePlayer", "m_skybox3d.origin");
	M_NETVAR(m_skybox3d_area, int, "CBasePlayer", "m_skybox3d.area");
	M_NETVAR(m_skybox3d_fog_enable, int, "CBasePlayer", "m_skybox3d.fog.enable");
	M_NETVAR(m_skybox3d_fog_blend, int, "CBasePlayer", "m_skybox3d.fog.blend");
	M_NETVAR(m_skybox3d_fog_dirPrimary, Vector, "CBasePlayer", "m_skybox3d.fog.dirPrimary");
	M_NETVAR(m_skybox3d_fog_colorPrimary, int, "CBasePlayer", "m_skybox3d.fog.colorPrimary");
	M_NETVAR(m_skybox3d_fog_colorSecondary, int, "CBasePlayer", "m_skybox3d.fog.colorSecondary");
	M_NETVAR(m_skybox3d_fog_start, float, "CBasePlayer", "m_skybox3d.fog.start");
	M_NETVAR(m_skybox3d_fog_end, float, "CBasePlayer", "m_skybox3d.fog.end");
	M_NETVAR(m_skybox3d_fog_maxdensity, float, "CBasePlayer", "m_skybox3d.fog.maxdensity");
	M_NETVAR(m_skybox3d_fog_HDRColorScale, float, "CBasePlayer", "m_skybox3d.fog.HDRColorScale");
	M_NETVAR(m_audio_soundscapeIndex, int, "CBasePlayer", "m_audio.soundscapeIndex");
	M_NETVAR(m_audio_localBits, int, "CBasePlayer", "m_audio.localBits");
	M_NETVAR(m_audio_entIndex, int, "CBasePlayer", "m_audio.entIndex");
	M_NETVAR(m_flFriction, float, "CBasePlayer", "m_flFriction");
	M_NETVAR(m_iAmmo, void*, "CBasePlayer", "m_iAmmo");
	M_NETVAR(m_fOnTarget, int, "CBasePlayer", "m_fOnTarget");
	M_NETVAR(m_nTickBase, int, "CBasePlayer", "m_nTickBase");
	M_NETVAR(m_nNextThinkTick, int, "CBasePlayer", "m_nNextThinkTick");
	M_NETVAR(m_hLastWeapon, int, "CBasePlayer", "m_hLastWeapon");
	M_NETVAR(m_vecVelocity, Vector, "CBasePlayer", "m_vecVelocity[0]");
	M_NETVAR(m_vecBaseVelocity, Vector, "CBasePlayer", "m_vecBaseVelocity");
	M_NETVAR(m_hConstraintEntity, int, "CBasePlayer", "m_hConstraintEntity");
	M_NETVAR(m_vecConstraintCenter, Vector, "CBasePlayer", "m_vecConstraintCenter");
	M_NETVAR(m_flConstraintRadius, float, "CBasePlayer", "m_flConstraintRadius");
	M_NETVAR(m_flConstraintWidth, float, "CBasePlayer", "m_flConstraintWidth");
	M_NETVAR(m_flConstraintSpeedFactor, float, "CBasePlayer", "m_flConstraintSpeedFactor");
	M_NETVAR(m_bConstraintPastRadius, bool, "CBasePlayer", "m_bConstraintPastRadius");
	M_NETVAR(m_flDeathTime, float, "CBasePlayer", "m_flDeathTime");
	M_NETVAR(m_nWaterLevel, int, "CBasePlayer", "m_nWaterLevel");
	M_NETVAR(m_flLaggedMovementValue, float, "CBasePlayer", "m_flLaggedMovementValue");
	M_NETVAR(m_hTonemapController, int, "CBasePlayer", "m_hTonemapController");
	M_NETVAR(pl, void*, "CBasePlayer", "pl");
	M_NETVAR(deadflag, int, "CBasePlayer", "deadflag");
	M_NETVAR(m_vecViewOffset, Vector, "CBasePlayer", "m_vecViewOffset[0]");
	M_NETVAR(m_iFOV, int, "CBasePlayer", "m_iFOV");
	M_NETVAR(m_iFOVStart, int, "CBasePlayer", "m_iFOVStart");
	M_NETVAR(m_flFOVTime, float, "CBasePlayer", "m_flFOVTime");
	M_NETVAR(m_iDefaultFOV, int, "CBasePlayer", "m_iDefaultFOV");
	M_NETVAR(m_hZoomOwner, int, "CBasePlayer", "m_hZoomOwner");
	M_NETVAR(m_hVehicle, int, "CBasePlayer", "m_hVehicle");
	M_NETVAR(m_hUseEntity, int, "CBasePlayer", "m_hUseEntity");
	M_NETVAR(m_hViewEntity, int, "CBasePlayer", "m_hViewEntity");
	M_NETVAR(m_hGroundEntity, int, "CBasePlayer", "m_hGroundEntity");
	M_NETVAR(m_hElevator, int, "CBasePlayer", "m_hElevator");
	M_NETVAR(m_flHeightAboveElevator, float, "CBasePlayer", "m_flHeightAboveElevator");
	M_NETVAR(m_iHealth, int, "CBasePlayer", "m_iHealth");
	M_NETVAR(m_lifeState, unsigned char, "CBasePlayer", "m_lifeState");
	M_NETVAR(m_iBonusProgress, int, "CBasePlayer", "m_iBonusProgress");
	M_NETVAR(m_iBonusChallenge, int, "CBasePlayer", "m_iBonusChallenge");
	M_NETVAR(m_flMaxspeed, float, "CBasePlayer", "m_flMaxspeed");
	M_NETVAR(m_fFlags, int, "CBasePlayer", "m_fFlags");
	M_NETVAR(m_iObserverMode, int, "CBasePlayer", "m_iObserverMode");
	M_NETVAR(m_hObserverTarget, int, "CBasePlayer", "m_hObserverTarget");
	M_NETVAR(m_hViewModel, int, "CBasePlayer", "m_hViewModel[0]");
	M_NETVAR(m_szLastPlaceName, const char*, "CBasePlayer", "m_szLastPlaceName");
	M_NETVAR(m_vecLadderNormal, Vector, "CBasePlayer", "m_vecLadderNormal");
	M_NETVAR(m_ladderSurfaceProps, int, "CBasePlayer", "m_ladderSurfaceProps");
	M_NETVAR(m_ubEFNoInterpParity, int, "CBasePlayer", "m_ubEFNoInterpParity");
	M_NETVAR(m_hPostProcessCtrl, int, "CBasePlayer", "m_hPostProcessCtrl");
	M_NETVAR(m_hColorCorrectionCtrl, int, "CBasePlayer", "m_hColorCorrectionCtrl");
	M_NETVAR(m_PlayerFog_m_hCtrl, int, "CBasePlayer", "m_PlayerFog.m_hCtrl");

public:
	inline bool IsAlive() {
		return (m_lifeState() == 0); //LIFE_ALIVE == 0
	}
};