#pragma once

#include "color.h"

class IClientModelRenderable;
class IClientRenderable;
struct studiohdr_t;

enum ClientFrameStage_t {
	FRAME_UNDEFINED = -1,
	FRAME_START,
	FRAME_NET_UPDATE_START,
	FRAME_NET_UPDATE_POSTDATAUPDATE_START,
	FRAME_NET_UPDATE_POSTDATAUPDATE_END,
	FRAME_NET_UPDATE_END,
	FRAME_RENDER_START,
	FRAME_RENDER_END
};

enum EClientClass
{
	SurvivorBot = 219,
	Hunter = 209,
	Smoker = 215,
	Boomer = 0,
	Tank = 220,
	Witch = 221,
	Infected = 210,
	CTerrorWeapon = 183,
	CTerrorGun = 179,
	CTankClaw = 136,
	CSubMachinegun = 132,
	CSniperRifle = 126,
	CSmokerClaw = 124,
	CPumpShotgun = 116,
	CPropaneTank = 109,
	CPistol = 100,
	CPipeBombProjectile = 99,
	CPipeBomb = 98,
	CPainPills = 90,
	COxygenTank = 89,
	CPropMountedGun = 114,
	CMolotovProjectile = 88,
	CMolotov = 87,
	CPropMinigun = 113,
	CHunterClaw = 80,
	CGasCan = 78,
	CFirstAidKit = 58,
	CClaw = 31,
	CTEBullets = 155,
	CBoomerClaw = 27,
	CBaseShotgun = 18,
	CAutoShotgun = 2,
	CAssaultRifle = 1,
	NextBotCombatCharacter = 212,
	CInferno = 81,
	CVomit = 199,
	CTongue = 194,
	CThrow = 193,
	CLunge = 85,
	CBaseAbility = 3,
	CTutorLesson = 197,
	CTransitioningPlayer = 195,
	CTerrorViewModel = 182,
	CFuncRagdollFader = 71,
	CTerrorGameRulesProxy = 178,
	CSurvivorPosition = 134,
	CPropHealthCabinet = 112,
	CFinaleTrigger = 55,
	CClientPath = 32,
	CTerrorPlayerResource = 181,
	CTerrorPlayer = 180,
	CSurvivorRescue = 135,
	CWeaponAmmoSpawn = 203,
	CWeaponSpawn = 206,
	CPropGlowingObject = 111,
	CEnvWeaponFire = 53,
	CWeaponCSBaseGun = 205,
	CWeaponCSBase = 204,
	CBaseCSGrenade = 9,
	CCSGameRulesProxy = 35,
	CWeaponCubemap = 0,
	CWeaponCycler = 0,
	CPlantedC4 = 0,
	CCSTeam = 38,
	CCSPlayer = 36,
	CCSRagdoll = 37,
	CTEPlayerAnimEvent = 175,
	CBaseCSGrenadeProjectile = 10,
	CTestTraceline = 191,
	CTEWorldDecal = 192,
	CTESpriteSpray = 189,
	CTESprite = 188,
	CTESparks = 187,
	CTESmoke = 186,
	CTEShowLine = 185,
	CTEProjectedDecal = 177,
	CTEPlayerDecal = 176,
	CTEPhysicsProp = 174,
	CTEParticleSystem = 173,
	CTEMuzzleFlash = 172,
	CTELargeFunnel = 170,
	CTEKillPlayerAttachments = 169,
	CTEImpact = 168,
	CTEGlowSprite = 167,
	CTEShatterSurface = 184,
	CTEFootprintDecal = 164,
	CTEFizz = 163,
	CTEExplosion = 162,
	CTEEnergySplash = 161,
	CTEEffectDispatch = 160,
	CTEDynamicLight = 159,
	CTEDecal = 157,
	CTEClientProjectile = 156,
	CTEBubbleTrail = 154,
	CTEBubbles = 153,
	CTEBSPDecal = 152,
	CTEBreakModel = 151,
	CTEBloodStream = 150,
	CTEBloodSprite = 149,
	CTEBeamSpline = 148,
	CTEBeamRingPoint = 147,
	CTEBeamRing = 146,
	CTEBeamPoints = 145,
	CTEBeamLaser = 144,
	CTEBeamFollow = 143,
	CTEBeamEnts = 142,
	CTEBeamEntPoint = 141,
	CTEBaseBeam = 140,
	CTEArmorRicochet = 139,
	CTEMetalSparks = 171,
	CSteamJet = 131,
	CSmokeStack = 125,
	DustTrail = 208,
	CFireTrail = 57,
	SporeTrail = 218,
	SporeExplosion = 217,
	RocketTrail = 214,
	SmokeTrail = 216,
	CPropVehicleDriveable = 115,
	ParticleSmokeGrenade = 213,
	CParticleFire = 91,
	MovieExplosion = 211,
	CTEGaussExplosion = 166,
	CEnvQuadraticBeam = 49,
	CEmbers = 41,
	CEnvWind = 54,
	CPrecipitation = 106,
	CPrecipitationBlocker = 107,
	CBaseTempEntity = 20,
	CHandleTest = 79,
	CTeamplayRoundBasedRulesProxy = 138,
	CSpriteTrail = 130,
	CSpriteOriented = 129,
	CSprite = 128,
	CRagdollPropAttached = 119,
	CRagdollProp = 118,
	CPredictedViewModel = 108,
	CPoseController = 104,
	CGameRulesProxy = 77,
	CFuncSimpleLadder = 74,
	CInfoLadderDismount = 82,
	CFuncLadder = 67,
	CTEFoundryHelpers = 165,
	CEnvDetailController = 45,
	CWorld = 207,
	CWaterLODControl = 202,
	CWaterBullet = 201,
	CVoteController = 200,
	CVGuiScreen = 198,
	CPropJeep = 0,
	CPropVehicleChoreoGeneric = 0,
	CFuncPlayerInfectedClip = 70,
	CTriggerPlayerMovement = 196,
	CBaseTrigger = 22,
	CTest_ProxyToggle_Networkable = 190,
	CBaseTeamObjectiveResource = 19,
	CTeam = 137,
	CFlare = 0,
	CSun = 133,
	CParticlePerformanceMonitor = 92,
	CSpotlightEnd = 127,
	CSlideshowDisplay = 123,
	CShadowControl = 122,
	CSceneEntity = 121,
	CRopeKeyframe = 120,
	CRagdollManager = 117,
	CPhysBoxMultiplayer = 95,
	CPropDoorRotatingCheckpoint = 110,
	CBasePropDoor = 17,
	CDynamicProp = 40,
	CPostProcessController = 105,
	CPointCommentaryNode = 103,
	CPlayerResource = 102,
	CPlasma = 101,
	CPhysMagnet = 97,
	CPhysicsProp = 96,
	CBreakable = 28,
	CPhysBox = 94,
	CParticleSystem = 93,
	CMaterialModifyControl = 86,
	CLightGlow = 84,
	CInfoOverlayAccessor = 83,
	CFuncTrackTrain = 76,
	CFuncSmokeVolume = 75,
	CFuncRotating = 73,
	CFuncReflectiveGlass = 72,
	CFuncOccluder = 69,
	CFuncMoveLinear = 68,
	CFuncMonitor = 0,
	CFunc_LOD = 62,
	CFuncElevator = 66,
	CTEDust = 158,
	CFunc_Dust = 61,
	CFuncConveyor = 65,
	CFuncBrush = 64,
	CBreakableSurface = 30,
	CFuncAreaPortalWindow = 63,
	CFish = 59,
	CEntityFlame = 43,
	CFireSmoke = 56,
	CEnvTonemapController = 52,
	CEnvScreenEffect = 50,
	CEnvScreenOverlay = 51,
	CEnvProjectedTexture = 48,
	CEnvParticleScript = 47,
	CFogController = 60,
	CEnvDOFController = 46,
	CEntityParticleTrail = 44,
	CEntityDissolve = 42,
	CDynamicLight = 39,
	CColorCorrectionVolume = 34,
	CColorCorrection = 33,
	CBreakableProp = 29,
	CBeamSpotlight = 25,
	CBaseButton = 6,
	CBaseToggle = 21,
	CBasePlayer = 16,
	CBaseFlex = 13,
	CBaseEntity = 12,
	CBaseDoor = 11,
	CBaseCombatCharacter = 7,
	CBaseAnimatingOverlay = 5,
	CBoneFollower = 26,
	CBaseAnimating = 4,
	CAI_BaseNPC = 0,
	CBeam = 24,
	CBaseViewModel = 23,
	CBaseParticleEntity = 15,
	CBaseGrenade = 14,
	CBaseCombatWeapon = 8
};

enum MaterialThreadMode_t {
	MATERIAL_SINGLE_THREADED,
	MATERIAL_QUEUED_SINGLE_THREADED,
	MATERIAL_QUEUED_THREADED
};

enum NormalDecodeMode_t {
	NORMAL_DECODE_NONE = 0,
	NORMAL_DECODE_ATI2N = 1,
	NORMAL_DECODE_ATI2N_ALPHA = 2
};

enum MaterialVarType_t {
	MATERIAL_VAR_TYPE_FLOAT = 0,
	MATERIAL_VAR_TYPE_STRING,
	MATERIAL_VAR_TYPE_VECTOR,
	MATERIAL_VAR_TYPE_TEXTURE,
	MATERIAL_VAR_TYPE_INT,
	MATERIAL_VAR_TYPE_FOURCC,
	MATERIAL_VAR_TYPE_UNDEFINED,
	MATERIAL_VAR_TYPE_MATRIX,
	MATERIAL_VAR_TYPE_MATERIAL
};

enum MaterialVarFlags_t {
	MATERIAL_VAR_DEBUG = (1 << 0),
	MATERIAL_VAR_NO_DEBUG_OVERRIDE = (1 << 1),
	MATERIAL_VAR_NO_DRAW = (1 << 2),
	MATERIAL_VAR_USE_IN_FILLRATE_MODE = (1 << 3),
	MATERIAL_VAR_VERTEXCOLOR = (1 << 4),
	MATERIAL_VAR_VERTEXALPHA = (1 << 5),
	MATERIAL_VAR_SELFILLUM = (1 << 6),
	MATERIAL_VAR_ADDITIVE = (1 << 7),
	MATERIAL_VAR_ALPHATEST = (1 << 8),
	MATERIAL_VAR_MULTIPASS = (1 << 9),
	MATERIAL_VAR_ZNEARER = (1 << 10),
	MATERIAL_VAR_MODEL = (1 << 11),
	MATERIAL_VAR_FLAT = (1 << 12),
	MATERIAL_VAR_NOCULL = (1 << 13),
	MATERIAL_VAR_NOFOG = (1 << 14),
	MATERIAL_VAR_IGNOREZ = (1 << 15),
	MATERIAL_VAR_DECAL = (1 << 16),
	MATERIAL_VAR_ENVMAPSPHERE = (1 << 17),
	MATERIAL_VAR_NOALPHAMOD = (1 << 18),
	MATERIAL_VAR_ENVMAPCAMERASPACE = (1 << 19),
	MATERIAL_VAR_BASEALPHAENVMAPMASK = (1 << 20),
	MATERIAL_VAR_TRANSLUCENT = (1 << 21),
	MATERIAL_VAR_NORMALMAPALPHAENVMAPMASK = (1 << 22),
	MATERIAL_VAR_NEEDS_SOFTWARE_SKINNING = (1 << 23),
	MATERIAL_VAR_OPAQUETEXTURE = (1 << 24),
	MATERIAL_VAR_ENVMAPMODE = (1 << 25),
	MATERIAL_VAR_SUPPRESS_DECALS = (1 << 26),
	MATERIAL_VAR_HALFLAMBERT = (1 << 27),
	MATERIAL_VAR_WIREFRAME = (1 << 28),
	MATERIAL_VAR_ALLOWALPHATOCOVERAGE = (1 << 29)
};

enum PreviewImageRetVal_t {
	MATERIAL_PREVIEW_IMAGE_BAD = 0,
	MATERIAL_PREVIEW_IMAGE_OK,
	MATERIAL_NO_PREVIEW_IMAGE
};

enum MaterialPropertyTypes_t {
	MATERIAL_PROPERTY_NEEDS_LIGHTMAP = 0,
	MATERIAL_PROPERTY_OPACITY,
	MATERIAL_PROPERTY_REFLECTIVITY,
	MATERIAL_PROPERTY_NEEDS_BUMPED_LIGHTMAPS
};

enum ImageFormat {
	IMAGE_FORMAT_UNKNOWN = -1,
	IMAGE_FORMAT_RGBA8888 = 0,
	IMAGE_FORMAT_ABGR8888,
	IMAGE_FORMAT_RGB888,
	IMAGE_FORMAT_BGR888,
	IMAGE_FORMAT_RGB565,
	IMAGE_FORMAT_I8,
	IMAGE_FORMAT_IA88,
	IMAGE_FORMAT_P8,
	IMAGE_FORMAT_A8,
	IMAGE_FORMAT_RGB888_BLUESCREEN,
	IMAGE_FORMAT_BGR888_BLUESCREEN,
	IMAGE_FORMAT_ARGB8888,
	IMAGE_FORMAT_BGRA8888,
	IMAGE_FORMAT_DXT1,
	IMAGE_FORMAT_DXT3,
	IMAGE_FORMAT_DXT5,
	IMAGE_FORMAT_BGRX8888,
	IMAGE_FORMAT_BGR565,
	IMAGE_FORMAT_BGRX5551,
	IMAGE_FORMAT_BGRA4444,
	IMAGE_FORMAT_DXT1_ONEBITALPHA,
	IMAGE_FORMAT_BGRA5551,
	IMAGE_FORMAT_UV88,
	IMAGE_FORMAT_UVWQ8888,
	IMAGE_FORMAT_RGBA16161616F,
	IMAGE_FORMAT_RGBA16161616,
	IMAGE_FORMAT_UVLX8888,
	IMAGE_FORMAT_R32F,
	IMAGE_FORMAT_RGB323232F,
	IMAGE_FORMAT_RGBA32323232F,
	IMAGE_FORMAT_NV_DST16,
	IMAGE_FORMAT_NV_DST24,
	IMAGE_FORMAT_NV_INTZ,
	IMAGE_FORMAT_NV_RAWZ,
	IMAGE_FORMAT_ATI_DST16,
	IMAGE_FORMAT_ATI_DST24,
	IMAGE_FORMAT_NV_NULL,
	IMAGE_FORMAT_ATI2N,
	IMAGE_FORMAT_ATI1N,
	IMAGE_FORMAT_DXT1_RUNTIME,
	IMAGE_FORMAT_DXT5_RUNTIME,
	NUM_IMAGE_FORMATS
};

enum RenderTargetSizeMode_t {
	RT_SIZE_NO_CHANGE = 0,
	RT_SIZE_DEFAULT = 1,
	RT_SIZE_PICMIP = 2,
	RT_SIZE_HDR = 3,
	RT_SIZE_FULL_FRAME_BUFFER = 4,
	RT_SIZE_OFFSCREEN = 5,
	RT_SIZE_FULL_FRAME_BUFFER_ROUNDED_UP = 6
};

enum MaterialRenderTargetDepth_t {
	MATERIAL_RT_DEPTH_SHARED = 0x0,
	MATERIAL_RT_DEPTH_SEPARATE = 0x1,
	MATERIAL_RT_DEPTH_NONE = 0x2,
	MATERIAL_RT_DEPTH_ONLY = 0x3
};

enum MaterialContextType_t {
	MATERIAL_HARDWARE_CONTEXT,
	MATERIAL_QUEUED_CONTEXT,
	MATERIAL_NULL_CONTEXT
};

enum CompiledVtfFlags {
	TEXTUREFLAGS_POINTSAMPLE = 0x00000001,
	TEXTUREFLAGS_TRILINEAR = 0x00000002,
	TEXTUREFLAGS_CLAMPS = 0x00000004,
	TEXTUREFLAGS_CLAMPT = 0x00000008,
	TEXTUREFLAGS_ANISOTROPIC = 0x00000010,
	TEXTUREFLAGS_HINT_DXT5 = 0x00000020,
	TEXTUREFLAGS_SRGB = 0x00000040,
	TEXTUREFLAGS_NORMAL = 0x00000080,
	TEXTUREFLAGS_NOMIP = 0x00000100,
	TEXTUREFLAGS_NOLOD = 0x00000200,
	TEXTUREFLAGS_ALL_MIPS = 0x00000400,
	TEXTUREFLAGS_PROCEDURAL = 0x00000800,
	TEXTUREFLAGS_ONEBITALPHA = 0x00001000,
	TEXTUREFLAGS_EIGHTBITALPHA = 0x00002000,
	TEXTUREFLAGS_ENVMAP = 0x00004000,
	TEXTUREFLAGS_RENDERTARGET = 0x00008000,
	TEXTUREFLAGS_DEPTHRENDERTARGET = 0x00010000,
	TEXTUREFLAGS_NODEBUGOVERRIDE = 0x00020000,
	TEXTUREFLAGS_SINGLECOPY = 0x00040000,
	TEXTUREFLAGS_UNUSED_00080000 = 0x00080000,
	TEXTUREFLAGS_UNUSED_00100000 = 0x00100000,
	TEXTUREFLAGS_UNUSED_00200000 = 0x00200000,
	TEXTUREFLAGS_UNUSED_00400000 = 0x00400000,
	TEXTUREFLAGS_NODEPTHBUFFER = 0x00800000,
	TEXTUREFLAGS_UNUSED_01000000 = 0x01000000,
	TEXTUREFLAGS_CLAMPU = 0x02000000,
	TEXTUREFLAGS_VERTEXTEXTURE = 0x04000000,
	TEXTUREFLAGS_SSBUMP = 0x08000000,
	TEXTUREFLAGS_UNUSED_10000000 = 0x10000000,
	TEXTUREFLAGS_BORDER = 0x20000000,
	TEXTUREFLAGS_UNUSED_40000000 = 0x40000000,
	TEXTUREFLAGS_UNUSED_80000000 = 0x80000000
};

enum LightType_t {
	MATERIAL_LIGHT_DISABLE = 0,
	MATERIAL_LIGHT_POINT,
	MATERIAL_LIGHT_DIRECTIONAL,
	MATERIAL_LIGHT_SPOT
};

enum MaterialCullMode_t {
	MATERIAL_CULLMODE_CCW,
	MATERIAL_CULLMODE_CW
};

enum MaterialFogMode_t {
	MATERIAL_FOG_NONE,
	MATERIAL_FOG_LINEAR,
	MATERIAL_FOG_LINEAR_BELOW_FOG_Z
};

enum MaterialHeightClipMode_t {
	MATERIAL_HEIGHTCLIPMODE_DISABLE,
	MATERIAL_HEIGHTCLIPMODE_RENDER_ABOVE_HEIGHT,
	MATERIAL_HEIGHTCLIPMODE_RENDER_BELOW_HEIGHT
};

enum MaterialMatrixMode_t {
	MATERIAL_VIEW = 0,
	MATERIAL_PROJECTION,
	MATERIAL_TEXTURE0,
	MATERIAL_TEXTURE1,
	MATERIAL_TEXTURE2,
	MATERIAL_TEXTURE3,
	MATERIAL_TEXTURE4,
	MATERIAL_TEXTURE5,
	MATERIAL_TEXTURE6,
	MATERIAL_TEXTURE7,
	MATERIAL_MODEL,
	NUM_MATRIX_MODES = MATERIAL_MODEL + 1,
	NUM_TEXTURE_TRANSFORMS = MATERIAL_TEXTURE7 - MATERIAL_TEXTURE0 + 1
};

enum StencilOperation_t {
	STENCILOPERATION_KEEP = 1,
	STENCILOPERATION_ZERO = 2,
	STENCILOPERATION_REPLACE = 3,
	STENCILOPERATION_INCRSAT = 4,
	STENCILOPERATION_DECRSAT = 5,
	STENCILOPERATION_INVERT = 6,
	STENCILOPERATION_INCR = 7,
	STENCILOPERATION_DECR = 8
};

enum StencilComparisonFunction_t {
	STENCILCOMPARISONFUNCTION_NEVER = 1,
	STENCILCOMPARISONFUNCTION_LESS = 2,
	STENCILCOMPARISONFUNCTION_EQUAL = 3,
	STENCILCOMPARISONFUNCTION_LESSEQUAL = 4,
	STENCILCOMPARISONFUNCTION_GREATER = 5,
	STENCILCOMPARISONFUNCTION_NOTEQUAL = 6,
	STENCILCOMPARISONFUNCTION_GREATEREQUAL = 7,
	STENCILCOMPARISONFUNCTION_ALWAYS = 8
};

enum OverrideType_t {
	OVERRIDE_NORMAL = 0,
	OVERRIDE_BUILD_SHADOWS,
	OVERRIDE_DEPTH_WRITE,
	OVERRIDE_SSAO_DEPTH_WRITE
};

enum {
	EF_BONEMERGE = 0x001,
	EF_BRIGHTLIGHT = 0x002,
	EF_DIMLIGHT = 0x004,
	EF_NOINTERP = 0x008,
	EF_NOSHADOW = 0x010,
	EF_NODRAW = 0x020,
	EF_NORECEIVESHADOW = 0x040,
	EF_BONEMERGE_FASTCULL = 0x080,
	EF_ITEM_BLINK = 0x100,
	EF_PARENT_ANIMATES = 0x200,
	EF_MAX_BITS = 10
};

enum {
	SPAWN_PISTOL = 1,
	SPAWN_UZI,
	SPAWN_PUMP_SHOTGUN,
	SPAWN_AUTO_SHOTGUN,
	SPAWN_ASSAULT_RIFLE,
	SPAWN_SNIPER_RIFLE,
	SPAWN_FIRST_AID = 8,
	SPAWN_MOLOTOV,
	SPAWN_PIPEBOMB,
	SPAWN_PILLS = 11
};

enum {
	MATERIAL_ADAPTER_NAME_LENGTH = 512
};

enum {
	ADDDECAL_TO_ALL_LODS = -1
};

#define	FL_ONGROUND		(1 << 0)
#define FL_DUCKING		(1 << 1)
#define	FL_WATERJUMP	(1 << 2)
#define FL_ONTRAIN		(1 << 3)
#define FL_INRAIN		(1 << 4)
#define FL_FROZEN		(1 << 5)
#define FL_ATCONTROLS	(1 << 6)
#define	FL_CLIENT		(1 << 7)
#define FL_FAKECLIENT	(1 << 8)
#define	FL_INWATER		(1 << 9)

#define IN_ATTACK		(1 << 0)
#define IN_JUMP			(1 << 1)
#define IN_DUCK			(1 << 2)
#define IN_FORWARD		(1 << 3)
#define IN_BACK			(1 << 4)
#define IN_USE			(1 << 5)
#define IN_CANCEL		(1 << 6)
#define IN_LEFT			(1 << 7)
#define IN_RIGHT		(1 << 8)
#define IN_MOVELEFT		(1 << 9)
#define IN_MOVERIGHT	(1 << 10)
#define IN_ATTACK2		(1 << 11)
#define IN_RUN			(1 << 12)
#define IN_RELOAD		(1 << 13)
#define IN_ALT1			(1 << 14)
#define IN_ALT2			(1 << 15)
#define IN_SCORE		(1 << 16)
#define IN_SPEED		(1 << 17)
#define IN_WALK			(1 << 18)
#define IN_ZOOM			(1 << 19)
#define IN_WEAPON1		(1 << 20)
#define IN_WEAPON2		(1 << 21)
#define IN_BULLRUSH		(1 << 22)
#define IN_GRENADE1		(1 << 23)
#define IN_GRENADE2		(1 << 24)
#define	IN_ATTACK3		(1 << 25)

#define	MAX_EDICT_BITS				11
#define	MAX_EDICTS					(1<<MAX_EDICT_BITS)
#define MAX_SERVER_CLASS_BITS		9
#define MAX_SERVER_CLASSES			(1<<MAX_SERVER_CLASS_BITS)
#define NUM_ENT_ENTRY_BITS			(MAX_EDICT_BITS + 1)
#define NUM_ENT_ENTRIES				(1 << NUM_ENT_ENTRY_BITS)
#define ENT_ENTRY_MASK				(NUM_ENT_ENTRIES - 1)
#define INVALID_EHANDLE_INDEX		0xFFFFFFFF
#define NUM_SERIAL_NUM_BITS			(32 - NUM_ENT_ENTRY_BITS)

#define CREATERENDERTARGETFLAGS_HDR		0x00000001

#define STUDIO_NONE						0x00000000
#define STUDIO_RENDER					0x00000001
#define STUDIO_VIEWXFORMATTACHMENTS		0x00000002
#define STUDIO_DRAWTRANSLUCENTSUBMODELS 0x00000004
#define STUDIO_TWOPASS					0x00000008
#define STUDIO_STATIC_LIGHTING			0x00000010
#define STUDIO_WIREFRAME				0x00000020
#define STUDIO_ITEM_BLINK				0x00000040
#define STUDIO_NOSHADOWS				0x00000080
#define STUDIO_WIREFRAME_VCOLLIDE		0x00000100
#define STUDIO_GENERATE_STATS			0x01000000
#define STUDIO_SSAODEPTHTEXTURE			0x08000000
#define STUDIO_SHADOWDEPTHTEXTURE		0x40000000
#define STUDIO_TRANSPARENCY				0x80000000

#define	HITGROUP_GENERIC	0
#define	HITGROUP_HEAD		1
#define	HITGROUP_CHEST		2
#define	HITGROUP_STOMACH	3
#define HITGROUP_LEFTARM	4	
#define HITGROUP_RIGHTARM	5
#define HITGROUP_LEFTLEG	6
#define HITGROUP_RIGHTLEG	7
#define HITGROUP_GEAR		10

#define	CONTENTS_EMPTY			0
#define	CONTENTS_SOLID			0x1
#define	CONTENTS_WINDOW			0x2
#define	CONTENTS_AUX			0x4
#define	CONTENTS_GRATE			0x8
#define	CONTENTS_SLIME			0x10
#define	CONTENTS_WATER			0x20
#define	CONTENTS_BLOCKLOS		0x40
#define CONTENTS_OPAQUE			0x80
#define	LAST_VISIBLE_CONTENTS	0x80
#define ALL_VISIBLE_CONTENTS (LAST_VISIBLE_CONTENTS | (LAST_VISIBLE_CONTENTS-1))
#define CONTENTS_TESTFOGVOLUME	0x100
#define CONTENTS_UNUSED			0x200	
#define CONTENTS_UNUSED6		0x400
#define CONTENTS_TEAM1			0x800
#define CONTENTS_TEAM2			0x1000
#define CONTENTS_IGNORE_NODRAW_OPAQUE	0x2000
#define CONTENTS_MOVEABLE		0x4000
#define	CONTENTS_AREAPORTAL		0x8000
#define	CONTENTS_PLAYERCLIP		0x10000
#define	CONTENTS_MONSTERCLIP	0x20000
#define	CONTENTS_CURRENT_0		0x40000
#define	CONTENTS_CURRENT_90		0x80000
#define	CONTENTS_CURRENT_180	0x100000
#define	CONTENTS_CURRENT_270	0x200000
#define	CONTENTS_CURRENT_UP		0x400000
#define	CONTENTS_CURRENT_DOWN	0x800000
#define	CONTENTS_ORIGIN			0x1000000
#define	CONTENTS_MONSTER		0x2000000
#define	CONTENTS_DEBRIS			0x4000000
#define	CONTENTS_DETAIL			0x8000000
#define	CONTENTS_TRANSLUCENT	0x10000000
#define	CONTENTS_LADDER			0x20000000
#define CONTENTS_HITBOX			0x40000000

#define	MASK_ALL					(0xFFFFFFFF)
#define	MASK_SOLID					(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE)
#define	MASK_PLAYERSOLID			(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_PLAYERCLIP|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE)
#define	MASK_NPCSOLID				(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTERCLIP|CONTENTS_WINDOW|CONTENTS_MONSTER|CONTENTS_GRATE)
#define	MASK_WATER					(CONTENTS_WATER|CONTENTS_MOVEABLE|CONTENTS_SLIME)
#define	MASK_OPAQUE					(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_OPAQUE)
#define MASK_OPAQUE_AND_NPCS		(MASK_OPAQUE|CONTENTS_MONSTER)
#define MASK_BLOCKLOS				(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_BLOCKLOS)
#define MASK_BLOCKLOS_AND_NPCS		(MASK_BLOCKLOS|CONTENTS_MONSTER)
#define	MASK_VISIBLE				(MASK_OPAQUE|CONTENTS_IGNORE_NODRAW_OPAQUE)
#define MASK_VISIBLE_AND_NPCS		(MASK_OPAQUE_AND_NPCS|CONTENTS_IGNORE_NODRAW_OPAQUE)
#define	MASK_SHOT					(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTER|CONTENTS_WINDOW|CONTENTS_DEBRIS|CONTENTS_HITBOX)
#define MASK_SHOT_HULL				(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_MONSTER|CONTENTS_WINDOW|CONTENTS_DEBRIS|CONTENTS_GRATE)
#define MASK_SHOT_PORTAL			(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_MONSTER)
#define MASK_SOLID_BRUSHONLY		(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_GRATE)
#define MASK_PLAYERSOLID_BRUSHONLY	(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_PLAYERCLIP|CONTENTS_GRATE)
#define MASK_NPCSOLID_BRUSHONLY		(CONTENTS_SOLID|CONTENTS_MOVEABLE|CONTENTS_WINDOW|CONTENTS_MONSTERCLIP|CONTENTS_GRATE)
#define MASK_NPCWORLDSTATIC			(CONTENTS_SOLID|CONTENTS_WINDOW|CONTENTS_MONSTERCLIP|CONTENTS_GRATE)
#define MASK_SPLITAREAPORTAL		(CONTENTS_WATER|CONTENTS_SLIME)
#define MASK_CURRENT				(CONTENTS_CURRENT_0|CONTENTS_CURRENT_90|CONTENTS_CURRENT_180|CONTENTS_CURRENT_270|CONTENTS_CURRENT_UP|CONTENTS_CURRENT_DOWN)
#define	MASK_DEADSOLID				(CONTENTS_SOLID|CONTENTS_PLAYERCLIP|CONTENTS_WINDOW|CONTENTS_GRATE)

#define TEXTURE_GROUP_LIGHTMAP						"Lightmaps"
#define TEXTURE_GROUP_WORLD							"World textures"
#define TEXTURE_GROUP_MODEL							"Model textures"
#define TEXTURE_GROUP_VGUI							"VGUI textures"
#define TEXTURE_GROUP_PARTICLE						"Particle textures"
#define TEXTURE_GROUP_DECAL							"Decal textures"
#define TEXTURE_GROUP_SKYBOX						"SkyBox textures"
#define TEXTURE_GROUP_CLIENT_EFFECTS				"ClientEffect textures"
#define TEXTURE_GROUP_OTHER							"Other textures"
#define TEXTURE_GROUP_PRECACHED						"Precached"
#define TEXTURE_GROUP_CUBE_MAP						"CubeMap textures"
#define TEXTURE_GROUP_RENDER_TARGET					"RenderTargets"
#define TEXTURE_GROUP_UNACCOUNTED					"Unaccounted textures"
#define TEXTURE_GROUP_STATIC_INDEX_BUFFER			"Static Indices"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_DISP		"Displacement Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_COLOR	"Lighting Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_WORLD	"World Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_MODELS	"Model Verts"
#define TEXTURE_GROUP_STATIC_VERTEX_BUFFER_OTHER	"Other Verts"
#define TEXTURE_GROUP_DYNAMIC_INDEX_BUFFER			"Dynamic Indices"
#define TEXTURE_GROUP_DYNAMIC_VERTEX_BUFFER			"Dynamic Verts"
#define TEXTURE_GROUP_DEPTH_BUFFER					"DepthBuffer"
#define TEXTURE_GROUP_VIEW_MODEL					"ViewModel"
#define TEXTURE_GROUP_PIXEL_SHADERS					"Pixel Shaders"
#define TEXTURE_GROUP_VERTEX_SHADERS				"Vertex Shaders"
#define TEXTURE_GROUP_RENDER_TARGET_SURFACE			"RenderTarget Surfaces"
#define TEXTURE_GROUP_MORPH_TARGETS					"Morph Targets"

struct RenderableInstance_t {
	uint8_t m_nAlpha;
};

class KeyValues {
public:
	char __pad00[36]; //TODO: Confirm
};

struct MaterialAdapterInfo_t {
	char m_pDriverName[MATERIAL_ADAPTER_NAME_LENGTH];
	unsigned int m_VendorID;
	unsigned int m_DeviceID;
	unsigned int m_SubSysID;
	unsigned int m_Revision;
	int m_nDXSupportLevel;
	int m_nMaxDXSupportLevel;
	unsigned int m_nDriverVersionHigh;
	unsigned int m_nDriverVersionLow;
};

struct MaterialVideoMode_t {
	int m_Width;
	int m_Height;
	ImageFormat m_Format;
	int m_RefreshRate;
};

struct LightDesc_t {
	LightType_t m_Type;
	Vector m_Color;
	Vector m_Position;
	Vector m_Direction;
	float  m_Range;
	float m_Falloff;
	float m_Attenuation0;
	float m_Attenuation1;
	float m_Attenuation2;
	float m_Theta;
	float m_Phi;
	float m_ThetaDot;
	float m_PhiDot;
	unsigned int m_Flags;
	float OneOver_ThetaDot_Minus_PhiDot;
	float m_RangeSquared;
};

struct ShaderStencilState_t {
	bool m_bEnable;
	StencilOperation_t m_FailOp;
	StencilOperation_t m_ZFailOp;
	StencilOperation_t m_PassOp;
	StencilComparisonFunction_t m_CompareFunc;
	int m_nReferenceValue;
	uint32_t m_nTestMask;
	uint32_t m_nWriteMask;

	ShaderStencilState_t() {
		m_bEnable         = false;
		m_PassOp          = m_FailOp = m_ZFailOp = STENCILOPERATION_KEEP;
		m_CompareFunc     = STENCILCOMPARISONFUNCTION_ALWAYS;
		m_nReferenceValue = 0;
		m_nTestMask       = m_nWriteMask = 0xFFFFFFFF;
	}
};

struct DrawModelState_t {
	studiohdr_t* m_pStudioHdr;
	void* m_pStudioHWData;
	IClientRenderable* m_pRenderable;
	const matrix3x4_t* m_pModelToWorld;
	void* m_decals;
	int	m_drawFlags;
	int	m_lod;
};

struct ModelRenderInfo_t {
	Vector origin;
	Vector angles;
	IClientRenderable* pRenderable;
	const void* pModel;
	const matrix3x4_t* pModelToWorld;
	const matrix3x4_t* pLightingOffset;
	const Vector* pLightingOrigin;
	int flags;
	int entity_index;
	int skin;
	int body;
	int hitboxset;
	unsigned short instance;

	ModelRenderInfo_t()
	{
		pModelToWorld = NULL;
		pLightingOffset = NULL;
		pLightingOrigin = NULL;
	}
};

struct StaticPropRenderInfo_t {
	const matrix3x4_t* pModelToWorld;
	const void* pModel;
	IClientRenderable* pRenderable;
	Vector* pLightingOrigin;
	short skin;
	unsigned short instance;
};

struct DrawModelInfo_t {
	studiohdr_t*	m_pStudioHdr;
	void*			m_pHardwareData;
	void*			m_Decals;
	int				m_Skin;
	int				m_Body;
	int				m_HitboxSet;
	void*			m_pClientEntity;
	int				m_Lod;
	void*			m_pColorMeshes;
	bool			m_bStaticLighting;
	Vector			m_vecAmbientCube[6];
	int				m_nLocalLightCount;
	LightDesc_t		m_LocalLightDescs[4];
};

struct ModelRenderSystemData_t {
	IClientRenderable*		m_pRenderable;
	IClientModelRenderable* m_pModelRenderable;
	RenderableInstance_t	m_InstanceData;
};