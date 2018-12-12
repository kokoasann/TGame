#include "stdafx.h"
#include "GameCamera.h"
#include "Engine/graphics/font/FontRender.h"
#include "TestScene.h"


TestScene::TestScene()
{
}


TestScene::~TestScene()
{
}


bool TestScene::Start() {
	m_skinModel = NewGO<SkinModelRender>(0, "testmodel");
	m_skinModel->Init(L"Assets/modelData/Test.cmo");
	m_skinModel->SetPosition(CVector3::Zero());
	CQuaternion rot = CQuaternion::Identity();
	CQuaternion rr = CQuaternion::Identity();
	rr.SetRotationDeg(CVector3::AxisX(), 20.f);
	rot.SetRotationDeg(CVector3::AxisY(), 45.f);
	rot.Multiply(rr);
	m_skinModel->SetRotation(rot);
	m_skinModel->SetScale({ 30.f,30.f,30.f });
	m_skinModel->SetFbxUpAxis(enFbxUpAxisY);
	//font
	//m_font = NewGO<FontRender>(0, "testfont");
	m_camera = new GameCamera;
	return true;
}


void TestScene::Update() {

}