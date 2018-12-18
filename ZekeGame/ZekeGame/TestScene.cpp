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
	m_skinModel = NewGO<SkinModelRender>(0, "model");
	m_skinModel->Init(L"Assets/modelData/Octane.cmo");
	m_skinModel->SetPosition(CVector3::Zero());
	IGameObjectManager().AddShadowCaster(&m_skinModel->GetSkinModel());
	m_skinModel->SetFbxUpAxis(enFbxUpAxisY);
	CQuaternion r = CQuaternion::Identity();
	r.SetRotationDeg(CVector3::AxisX(), 90.f);
	m_skinModel->SetRotation(r);
	m_camera = new GameCamera;
	m_camera->SetTarget(CVector3::Zero());
	CVector3 ppp = CVector3::Zero();
	ppp.z -= 3.f;

	m_bg = NewGO<SkinModelRender>(0, "bg");
	m_bg->Init(L"Assets/modelData/testtt.cmo");
	m_bg->SetPosition(CVector3::Zero());
	m_camera->SetPosition(ppp);
	m_camera->Update();
	return true;
}


void TestScene::Update() {
	if (g_pad[0].IsPress(enButtonLeft)) {
		pos.y += 10.f;
	}
	if (g_pad[0].IsPress(enButtonRight)) {
		pos.y -= 10.f;
	}
	pos.x -= g_pad[0].GetLStickXF() * 10.f;
	pos.z -= g_pad[0].GetLStickYF() * 10.f;
	m_skinModel->SetPosition(pos);
	m_camera->Update();
}