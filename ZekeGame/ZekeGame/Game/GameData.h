#pragma once
#include "Monster/Monster.h"
#include "Monster/MonsterAction.h"

extern Monster* g_mons[64];

enum MonsterID
{
	enTest,
	enUmataur,
};

enum ActionID
{
	enChase,
	enAtack,
	enLeave,
};

//static std::vector<Monster*> g_mons;
extern int g_buddyCount;
extern int g_enemyCount;
extern int g_monsCount;
extern int g_meNum;
extern int g_meTeam;
static void deletemons(Monster* mon)
{
	for (Monster* gmon : g_mons)
	{
		for (auto ac : gmon->Getactions())
		{
			if(ac->Gettarget() == mon)
				ac->Settarget(nullptr);
		}
	}
	for (int i = mon->Getnum(); i < g_monsCount; i++)
	{
		g_mons[i] = g_mons[i + 1];
	}
	/*std::vector<Monster*>::iterator ite = std::find(g_mons.begin(), g_mons.end(), mon);
	g_mons.erase(ite);*/
}
class GameData
{
public:
	void deletemons(Monster* mon);
	
};