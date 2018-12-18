#include "stdafx.h"
#include "Game.h"
#include "GameCamera2D.h"
#include "Title/pvpModeSelect.h"
#include "Title/ModeSelect.h"
#include "../TestScene.h"

int WINAPI wWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR lpCmdLine,
	int nCmdShow) {
	//Initialize
	Engine::IEngine().Init(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
	//NewGO<Game>(0,"Game");
	//NewGO<PvPModeSelect>(0, "pvp");
	NewGO<GameCamera2D>(0, "cam2d");
	//NewGO<ModeSelect>(0, "modesel");
	NewGO<TestScene>(0, "22");
	//MainRoop
	Engine::IEngine().GameRoop();
	//Release
	Engine::IEngine().Final();
}
