#pragma once
#include "Engine/graphics/font/FontRender.h"
class TestScene : public GameObject
{
public:
	TestScene();
	~TestScene();
	bool Start();
	void Update();
	void PostRender();
private:
	SkinModelRender* m_skinModel;
	SpriteRender* m_sprite;
	//SpriteRender* m_sprite1;
	//CFont m_font;
	GameCamera* m_camera;
	//FontRender* m_font;
	FontRender * m_fontRender;
};
