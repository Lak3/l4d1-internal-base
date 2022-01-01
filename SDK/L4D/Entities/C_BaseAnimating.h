#pragma once

#include "C_BaseEntity.h"

#define MAXSTUDIOBONES		128
#define MAXSTUDIOPOSEPARAM	24
#define MAXSTUDIOBONECTRLS	4

class CChoreoScene;
class CChoreoEvent;
class CChoreoActor;
class CSceneEventInfo;

enum ModelDataCategory_t {
	MODEL_DATA_LIGHTING_MODEL,
	MODEL_DATA_STENCIL,
	MODEL_DATA_CATEGORY_COUNT
};

class IClientModelRenderable
{
public:
	virtual bool GetRenderData(void* pData, ModelDataCategory_t nCategory) = 0;
};

class C_BaseAnimating : public C_BaseEntity, public IClientModelRenderable
{
public:
	enum {
		NUM_POSEPAREMETERS = 24,
		NUM_BONECTRLS = 4
	};

public:
	virtual						~C_BaseAnimating() = 0;

	virtual void				GetBoneControllers(float controllers[MAXSTUDIOBONECTRLS]) = 0;
	virtual float				SetBoneController(int iController, float flValue) = 0;
	virtual void				GetPoseParameters(CStudioHdr* pStudioHdr, float poseParameter[MAXSTUDIOPOSEPARAM]) = 0;
	virtual void				BuildTransformations(CStudioHdr* pStudioHdr, void* pos, void* q, const matrix3x4_t& cameraTransform, int boneMask, void* boneComputed) = 0;
	virtual void				ApplyBoneMatrixTransform(matrix3x4_t& transform) = 0;
	virtual void				UpdateIKLocks(float currentTime) = 0;
	virtual void				CalculateIKLocks(float currentTime) = 0;
	virtual int					InternalDrawModel(int flags, const RenderableInstance_t& instance) = 0;
	virtual bool				OnInternalDrawModel(void* pInfo) = 0;
	virtual void				ControlMouth(CStudioHdr* pStudioHdr) = 0;
	virtual void				DoAnimationEvents(CStudioHdr* pStudio) = 0;
	virtual void				FireEvent(const Vector& origin, const Vector& angles, int event, const char* options) = 0;
	virtual void				FireObsoleteEvent(const Vector& origin, const Vector& angles, int event, const char* options) = 0;
	virtual bool				DispatchMuzzleEffect(const char* options, bool isFirstPerson) = 0;
	virtual void				EjectParticleBrass(const char* pEffectName, const int iAttachment) = 0;
	virtual	void				StandardBlendingRules(CStudioHdr* pStudioHdr, void* pos, void* q, float currentTime, int boneMask) = 0;
	virtual void				MaintainSequenceTransitions(void* boneSetup, float flCycle, void* pos, void* q) = 0;
	virtual void				AccumulateLayers(void* boneSetup, void* pos, void* q, float currentTime) = 0;
	virtual void				CachePoseParameters(void) = 0;
	virtual C_BaseAnimating*	BecomeRagdollOnClient() = 0;
	virtual int					GetRagdollType(void) const = 0;
	virtual void				SaveRagdollInfo(int numbones, const matrix3x4_t& cameraTransform, void* pBoneToWorld) = 0;
	virtual bool				RetrieveRagdollInfo(void* pos, void* q) = 0;
	virtual void				GetRagdollInitBoneArrays(matrix3x4_t* pDeltaBones0, matrix3x4_t* pDeltaBones1, matrix3x4_t* pCurrentBones, float boneDt) = 0;
	virtual void				StudioFrameAdvance() = 0;
	virtual float				FrameAdvance(float flInterval = 0.0f) = 0;
	virtual float				GetSequenceCycleRate(CStudioHdr* pStudioHdr, int iSequence) = 0;
	virtual void				UpdateClientSideAnimation() = 0;
	virtual unsigned int		ComputeClientSideAnimationFlags() = 0;
	virtual bool				IsActivityFinished(void) = 0;
	virtual void				UncorrectViewModelAttachment(Vector& vOrigin) = 0;
	virtual void				DoMuzzleFlash() = 0;
	virtual void				ProcessMuzzleFlashEvent() = 0;
	virtual void				SetServerIntendedCycle(float intended) = 0;
	virtual float				GetServerIntendedCycle(void) = 0;
	virtual bool				ShouldResetSequenceOnNewModel(void) = 0;
	virtual bool				IsViewModel(void) const = 0;
	virtual void				FormatViewModelAttachment(int nAttachment, matrix3x4_t& attachmentToWorld) = 0;
	virtual bool				IsMenuModel() const = 0;
	virtual bool				CalcAttachments() = 0;
	virtual bool				ComputeStencilState(void* pStencilState) = 0;
	virtual float				LastBoneChangedTime() = 0;

public:
	M_NETVAR(m_nForceBone, int, "CBaseAnimating", "m_nForceBone");
	M_NETVAR(m_vecForce, Vector, "CBaseAnimating", "m_vecForce");
	M_NETVAR(m_nSkin, int, "CBaseAnimating", "m_nSkin");
	M_NETVAR(m_nSequence, int, "CBaseAnimating", "m_nSequence");
	M_NETVAR(m_nBody, int, "CBaseAnimating", "m_nBody");
	M_NETVAR(m_nHitboxSet, int, "CBaseAnimating", "m_nHitboxSet");
	M_NETVAR(m_flModelWidthScale, float, "CBaseAnimating", "m_flModelWidthScale");
	M_NETVAR(m_flPoseParameter, void*, "CBaseAnimating", "m_flPoseParameter");
	M_NETVAR(m_flPlaybackRate, float, "CBaseAnimating", "m_flPlaybackRate");
	M_NETVAR(m_flEncodedController, void*, "CBaseAnimating", "m_flEncodedController");
	M_NETVAR(m_bClientSideAnimation, bool, "CBaseAnimating", "m_bClientSideAnimation");
	M_NETVAR(m_bClientSideFrameReset, bool, "CBaseAnimating", "m_bClientSideFrameReset");
	M_NETVAR(m_bClientSideRagdoll, bool, "CBaseAnimating", "m_bClientSideRagdoll");
	M_NETVAR(m_nNewSequenceParity, int, "CBaseAnimating", "m_nNewSequenceParity");
	M_NETVAR(m_nResetEventsParity, int, "CBaseAnimating", "m_nResetEventsParity");
	M_NETVAR(m_nMuzzleFlashParity, int, "CBaseAnimating", "m_nMuzzleFlashParity");
	M_NETVAR(m_hLightingOrigin, int, "CBaseAnimating", "m_hLightingOrigin");
	M_NETVAR(m_flCycle, float, "CBaseAnimating", "m_flCycle");

public:
	inline bool GetHitboxPositionByGroup(const int nGroup, Vector& vPos)
	{
		const model_t* pModel = this->GetModel();

		if (!pModel)
			return false;

		const studiohdr_t* pHdr = I::ModelInfo->GetStudiomodel(pModel);

		if (!pHdr)
			return false;

		const mstudiohitboxset* pSet = pHdr->pHitboxSet(this->m_nHitboxSet());

		if (!pSet)
			return false;

		matrix3x4_t Matrix[MAXSTUDIOBONES];
		if (!this->SetupBones(Matrix, MAXSTUDIOBONES, 0x100, I::GlobalVars->curtime))
			return false;

		mstudiobbox* pFinalBox = nullptr;

		for (int n = 0; n < pSet->numhitboxes; n++)
		{
			mstudiobbox* pBox = pSet->pHitbox(n);

			if (!pBox || (pBox->group != nGroup) || (pBox->bone < 0) || (pBox->bone >= MAXSTUDIOBONES))
				continue;

			pFinalBox = pBox;
		}

		if (!pFinalBox)
			return false;

		U::Math.VectorTransform((pFinalBox->bbmin + pFinalBox->bbmax) * 0.5f, Matrix[pFinalBox->bone], vPos);
		return true;
	}
};

class C_BaseAnimatingOverlay : public C_BaseAnimating
{
public:
	enum {
		MAX_OVERLAYS = 15,
	};

public:
	virtual ~C_BaseAnimatingOverlay() = 0;

public:
	M_NETVAR(m_flCycle, float, "CBaseAnimatingOverlay", "m_flCycle");
	M_NETVAR(m_flPrevCycle, float, "CBaseAnimatingOverlay", "m_flPrevCycle");
	M_NETVAR(m_flWeight, float, "CBaseAnimatingOverlay", "m_flWeight");
	M_NETVAR(m_nOrder, int, "CBaseAnimatingOverlay", "m_nOrder");
};

class C_BaseFlex : public C_BaseAnimatingOverlay
{
public:
	enum {
		PHONEME_CLASS_WEAK = 0,
		PHONEME_CLASS_NORMAL,
		PHONEME_CLASS_STRONG,
		NUM_PHONEME_CLASSES
	};

public:
	virtual				~C_BaseFlex() = 0;

	virtual void		InitPhonemeMappings() = 0;
	virtual bool		OwnsChoreoScene(CChoreoScene* unk1) const = 0;
	virtual void		OverrideBlinkWeight(float unk1) const = 0;
	virtual bool		StartSceneEvent(CSceneEventInfo* info, CChoreoScene* scene, CChoreoEvent* evnt, CChoreoActor* actor, C_BaseEntity* pTarget) = 0;
	virtual bool		ProcessSequenceSceneEvent(CSceneEventInfo* info, CChoreoScene* scene, CChoreoEvent* evnt) = 0;
	virtual	bool		ClearSceneEvent(CSceneEventInfo* info, bool fastKill, bool canceled) = 0;
	virtual bool		CheckSceneEventCompletion(CSceneEventInfo* info, float currenttime, CChoreoScene* scene, CChoreoEvent* evnt) = 0;

private:
	virtual void* __pad05() = 0;
	virtual void* __pad06() = 0;
	virtual void* __pad07() = 0;

public:
	M_NETVAR(m_flexWeight, void*, "CBaseFlex", "m_flexWeight");
	M_NETVAR(m_blinktoggle, bool, "CBaseFlex", "m_blinktoggle");
	M_NETVAR(m_viewtarget, Vector, "CBaseFlex", "m_viewtarget");
};