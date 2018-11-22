#include "stdafx.h"
#include "StageSetup.h"
#include "../GameData.h"
#include "../Monster/Monster.h"
#include "../Monster/Monsters/TestMons.h"
#include <array>

StageSetup::StageSetup()
{
	
}

StageSetup::~StageSetup()
{
}

void StageSetup::PVPSetup(std::vector<std::string> files, int monsterAI[6])
{
	//std::string* path = new std::string("PythonAIs.");
	std::string* path = new std::string("");
	*path += files[monsterAI[0]];
	Monster* mons = NewGO<TestMons>(0, "monster");
	mons->Setpos({ 0,0,500 });
	mons->Setnum(0);
	mons->Setteam(0);
	mons->SetpyFile(path->c_str());
	//g_mons.push_back(mons);
	g_mons[0] = mons;

	//path = new std::string("PythonAIs.");
	path = new std::string("");
	*path += files[monsterAI[1]];
	mons = NewGO<TestMons>(0, "monster");
	mons->Setpos({ 250,0,500 });
	mons->Setnum(1);
	mons->Setteam(0);
	mons->SetpyFile(path->c_str());
	//g_mons.push_back(mons);
	g_mons[1] = mons;

	//path = new std::string("PythonAIs.");
	path = new std::string("");
	*path += files[monsterAI[2]];
	mons = NewGO<TestMons>(0, "monster");
	mons->Setpos({ -250,0,500 });
	mons->Setnum(2);
	mons->Setteam(0);
	mons->SetpyFile(path->c_str());
	//g_mons.push_back(mons);
	g_mons[2] = mons;


	//path = new std::string("PythonAIs.");
	path = new std::string("");
	*path += files[monsterAI[3]];
	mons = NewGO<TestMons>(0, "monster");
	mons->Setpos({ 0,0,-500 });
	mons->Setnum(3);
	mons->Setteam(1);
	mons->SetpyFile(path->c_str());
	//g_mons.push_back(mons);
	g_mons[3] = mons;

	//path = new std::string("PythonAIs.");
	path = new std::string("");
	*path += files[monsterAI[4]];
	mons = NewGO<TestMons>(0, "monster");
	mons->Setpos({ 250,0,-500 });
	mons->Setnum(4);
	mons->Setteam(1);
	mons->SetpyFile(path->c_str());
	//g_mons.push_back(mons);
	g_mons[4] = mons;

	//path = new std::string("PythonAIs.");
	path = new std::string("");
	*path += files[monsterAI[5]];
	mons = NewGO<TestMons>(0, "monster");
	mons->Setpos({ -250,0,-500 });
	mons->Setnum(5);
	mons->Setteam(1);
	mons->SetpyFile(path->c_str());
	//g_mons.push_back(mons);
	g_mons[5] = mons;

	g_buddyCount = 0;
	g_enemyCount = 0;
	g_monsCount = 6;
}
