#include "stdafx.h"
#include "StageSetup.h"
#include "../GameData.h"
#include "../Monster/Monster.h"
#include "../Monster/Monsters/TestMons.h"
#include "../Monster/Monsters/Uma.h"
#include <array>

StageSetup::StageSetup()
{
	
}

StageSetup::~StageSetup()
{
}

void StageSetup::PVPSetup(std::vector<std::string> files, int monsterAI[6],MonsterID monids[6])
{
	int team = 0;
	int num = 0;
	CVector3 poss[6];
	poss[0] = { 0,0,500 };
	poss[1] = { 250,0,500 };
	poss[2] = { -250,0,500 };
	poss[3] = { 0,0,-500 };
	poss[4] = { 250,0,-500 };
	poss[5] = { -250,0,-500 };

	for (int i = 0; i < 6; i++)
	{
		if (i == 3)
			team++;

		Monster* mon = nullptr;
		switch (monids[i])
		{
		case enTest:
			mon = NewGO<TestMons>(0, "monster");
			break;
		case enUmataur:
			mon = NewGO<Uma>(0, "monster");
			break;
		}
		mon->Setpos(poss[i]);
		mon->Setnum(i);
		mon->Setteam(team);
		std::string* path = new std::string("PythonAIs.");
		//std::string* path = new std::string("");
		*path += files[monsterAI[0]];
		mon->SetpyFile(path->c_str());
		g_mons[i] = mon;

	}

	//std::string* path = new std::string("PythonAIs.");
	////std::string* path = new std::string("");
	//*path += files[monsterAI[0]];
	//Monster* mons = NewGO<Uma>(0, "monster");
	//mons->Setpos({ 0,0,500 });
	//mons->Setnum(0);
	//mons->Setteam(0);
	//mons->SetpyFile(path->c_str());
	////g_mons.push_back(mons);
	//g_mons[0] = mons;

	//path = new std::string("PythonAIs.");
	////path = new std::string("");
	//*path += files[monsterAI[1]];
	//mons = NewGO<TestMons>(0, "monster");
	//mons->Setpos({ 250,0,500 });
	//mons->Setnum(1);
	//mons->Setteam(0);
	//mons->SetpyFile(path->c_str());
	////g_mons.push_back(mons);
	//g_mons[1] = mons;

	//path = new std::string("PythonAIs.");
	////path = new std::string("");
	//*path += files[monsterAI[2]];
	//mons = NewGO<TestMons>(0, "monster");
	//mons->Setpos({ -250,0,500 });
	//mons->Setnum(2);
	//mons->Setteam(0);
	//mons->SetpyFile(path->c_str());
	////g_mons.push_back(mons);
	//g_mons[2] = mons;


	//path = new std::string("PythonAIs.");
	////path = new std::string("");
	//*path += files[monsterAI[3]];
	//mons = NewGO<TestMons>(0, "monster");
	//mons->Setpos({ 0,0,-500 });
	//mons->Setnum(3);
	//mons->Setteam(1);
	//mons->SetpyFile(path->c_str());
	////g_mons.push_back(mons);
	//g_mons[3] = mons;

	//path = new std::string("PythonAIs.");
	////path = new std::string("");
	//*path += files[monsterAI[4]];
	//mons = NewGO<TestMons>(0, "monster");
	//mons->Setpos({ 250,0,-500 });
	//mons->Setnum(4);
	//mons->Setteam(1);
	//mons->SetpyFile(path->c_str());
	////g_mons.push_back(mons);
	//g_mons[4] = mons;

	//path = new std::string("PythonAIs.");
	////path = new std::string("");
	//*path += files[monsterAI[5]];
	//mons = NewGO<TestMons>(0, "monster");
	//mons->Setpos({ -250,0,-500 });
	//mons->Setnum(5);
	//mons->Setteam(1);
	//mons->SetpyFile(path->c_str());
	////g_mons.push_back(mons);
	//g_mons[5] = mons;

	g_buddyCount = 3;
	g_enemyCount = 3;
	g_monsCount = 6;
}
