#include "stdafx.h"
#include "GameCamera.h"
#include "TestScene.h"


TestScene::TestScene()
{
}


TestScene::~TestScene()
{
}


bool TestScene::Start() {
	m_skinModel = NewGO<SkinModelRender>(0, "testmodel");
	m_skinModel->Init(L"Assets/modelData/Octane.cmo");
	m_skinModel->SetPosition(CVector3::Zero());
	IGameObjectManager().AddShadowCaster(&m_skinModel->GetSkinModel());

	CQuaternion rr = CQuaternion::Identity();
	rr.SetRotationDeg(CVector3::AxisX(), 90.f);
	m_rot.Multiply(rr);
	m_skinModel->SetRotation(m_rot);
	m_skinModel->SetScale({ 30.f,30.f,30.f });
	m_skinModel->SetFbxUpAxis(enFbxUpAxisY);
	m_camera = new GameCamera;
	return true;
}


void TestScene::Update() {
	if (g_pad[0].IsPress(enButtonRight)) {
		CQuaternion rot = CQuaternion::Identity();
		rot.SetRotationDeg(CVector3::AxisX(), 10.f);
		m_rot.Multiply(rot);
	}
	if (g_pad[0].IsPress(enButtonLeft)) {
		CQuaternion rot = CQuaternion::Identity();
		rot.SetRotationDeg(CVector3::AxisY(), 10.f);
		m_rot.Multiply(rot);
	}
	if (g_pad[0].IsPress(enButtonUp)) {
		CQuaternion rot = CQuaternion::Identity();
		rot.SetRotationDeg(CVector3::AxisZ(), 10.f);
		m_rot.Multiply(rot);
	}
	m_skinModel->SetRotation(m_rot);
}