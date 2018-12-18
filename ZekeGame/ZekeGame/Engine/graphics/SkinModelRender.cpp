#include "stdafx.h"
#include "SkinModelRender.h"


SkinModelRender::SkinModelRender()
{
}


SkinModelRender::~SkinModelRender()
{
}


bool SkinModelRender::Start() {
	return true;
}

void SkinModelRender::Update() {
	m_animation.Update(IGameTime().GetFrameDeltaTime());
	m_skinModel.UpdateWorldMatrix(m_pos, m_rot, m_scale);
	m_animation.Update(IGameTime().GetFrameDeltaTime());
}

void SkinModelRender::Render() {
	m_skinModel.SetDirColor(m_dirCol,0);
	m_skinModel.SetDirLight(m_dirLight,0);
	m_skinModel.Draw(enRenderMode_Normal,
		camera3d->GetViewMatrix(),
		camera3d->GetProjectionMatrix());
	m_skinModel.SetDirColor(m_defCol,0);
	m_skinModel.SetDirLight(m_defDir,0);
}


void SkinModelRender::Init(const wchar_t* filePath,
	AnimationClip* animationClips,
	int numAnimationClips,
	EnFbxUpAxis fbxUpAxis,
	const char* psmain,
	const char* vsmain){
	m_enFbxUpAxis = fbxUpAxis;
	m_psmain = psmain;
	m_vsmain = vsmain;
	m_skinModel.Init(filePath,m_enFbxUpAxis, m_psmain, m_vsmain);
	InitAnimation(animationClips, numAnimationClips);
}

void SkinModelRender::InitAnimation(AnimationClip* animationClips, int numAnimationClips) {
	m_animationClips = animationClips;
	m_numAnimationClips = numAnimationClips;
	if (m_animationClips != nullptr) {
		m_animation.Init(m_skinModel, m_animationClips, m_numAnimationClips);
	}
}