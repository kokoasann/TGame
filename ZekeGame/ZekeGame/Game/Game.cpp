#include "stdafx.h"
#include "Game.h"
#include "GameCamera.h"
#include "GameData.h"


#include "PythonBridge/PythonBridge.h"
#include "Monster/MonsterActionManeger.h"
#include "Monster/Monsters/TestMons.h"

#include "Result/Win/Win.h"

Game::Game()
{
}


Game::~Game()
{
	for (auto mon : g_mons)
	{
		if (mon == NULL)
			break;
		DeleteGO(mon);
	}
	DeleteGO(m_model);
	DeleteGO(m_sprite);
	Engine::IEngine().DestroyNetworkSystem();
	delete m_pi;
}

void Game::GamePVPmodeInit(std::vector<std::string> files, int monsterAI[6],MonsterID MonsterID[6])
{
	ss = new StageSetup();
	ss->PVPSetup(files, monsterAI,MonsterID);
	playMode = enLocalPVP;
}

bool Game::Start() {
	
	m_pi = new Pyinit;
	
	NewGO<MonsterActionManeger>(0, "MAM");
	m_model = NewGO<SkinModelRender>(0, "model");
	m_model->Init(L"Assets/modelData/map.cmo");
	m_model->SetPosition(CVector3::Zero());


	/*m_sprite = NewGO<SpriteRender>(0,"sprite");
	m_sprite->Init(L"Assets/Sprite/Test.dds", 500.f, 500.f);
	m_sprite->SetPosition(CVector3::Zero());*/

	Engine::IEngine().CreateNetworkSystem();

	camera = new GameCamera;

	return true;
}
void Game::Update() {
	static CVector3 pos = CVector3::Zero();
	/*if (g_pad[0].IsPress(enButtonDown)) {
		pos.x += 50.0f;
	}*/
	m_model->SetPosition(pos);
	camera->SetTarget(CVector3::Zero());
	camera->SetPosition({ 0.0f, 350.0f, 1000.0f });
	camera->Update();
	if (!m_END)
	{
		if (g_buddyCount == 0 || g_enemyCount == 0)
		{
			m_END = true;
			int team = g_mons[0]->Getteam();
			Win* win;
			switch (playMode)
			{
			case enLocalPVP:
				win = NewGO<Win>(0,"win");
				win->init(team);
				break;
			case enRandomPVP:

				break;
			case enAdventure:
				break;
			}
		}
	}
}

void Game::Render() {
}

void Game::PostRender() {
}