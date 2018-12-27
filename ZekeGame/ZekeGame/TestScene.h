#pragma once
class TestScene : public GameObject
{
public:
	TestScene();
	~TestScene();
	bool Start();
	void Update();
private:
	SkinModelRender* m_skinModel;
	SkinModelRender* m_skinModel2;
	SkinModelRender* m_bg;
	GameCamera* m_camera;
	CQuaternion m_rot = CQuaternion::Identity();
	CVector3 pos = CVector3::Zero();
};
