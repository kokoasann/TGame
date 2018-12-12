#pragma once
//#include "GameCamera.h"

#include "StageSetup/StageSetup.h"

enum MonsterID;
class GameCamera;
class TestListener;
struct Pyinit;
class Game : public GameObject
{
public:
	Game();
	~Game();
	void GamePVPmodeInit(std::vector<std::string> files, int monsterAI[6], MonsterID MonsterID[6]);
	bool Start() override;
	void Update() override;
	void Render() override;
	void PostRender() override;

	enum Mode
	{
		enLocalPVP,
		enRandomPVP,
		enAdventure
	};

private:
	Pyinit* m_pi;
	SkinModelRender* m_model;
	SpriteRender* m_sprite;
	GameCamera* camera = nullptr;
	StageSetup* ss;

	Mode playMode = enLocalPVP;

	bool m_END = false;
};

