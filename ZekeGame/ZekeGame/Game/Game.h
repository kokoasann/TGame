#pragma once
//#include "GameCamera.h"

class GameCamera;

class Game : public GameObject
{
public:
	Game();
	~Game();
	bool Start() override;
	void Update() override;
	void Render() override;
	void PostRender() override;
private:
	SkinModelRender* m_model;
	SpriteRender* m_sprite;
	GameCamera* camera = nullptr;
};

