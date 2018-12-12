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
	SpriteRender* m_sprite;
	GameCamera* m_camera;
	FontRender* m_font;
};
