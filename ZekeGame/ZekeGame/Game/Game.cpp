#include "stdafx.h"
#include "Game.h"
#include "GameCamera.h"
#include "GameData.h"


#include "PythonBridge/PythonBridge.h"
#include "Monster/MonsterActionManeger.h"
#include "Monster/Monsters/TestMons.h"

Game::Game()
{
}


Game::~Game()
{
	DeleteGO(m_model);
	DeleteGO(m_sprite);
	Engine::IEngine().DestroyNetworkSystem();
	delete m_pi;
}

void Game::GamePVPmodeInit(std::vector<std::string> files, int monsterAI[6])
{
	ss = new StageSetup();
	ss->PVPSetup(files, monsterAI);
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
	if (g_pad[0].IsPress(enButtonDown)) {
		pos.x += 50.0f;
	}
	m_model->SetPosition(pos);
	camera->SetTarget(CVector3::Zero());
	camera->SetPosition({ 0.0f, 350.0f, 1000.0f });
	camera->Update();
}

void Game::Render() {
}

void Game::PostRender() {
}