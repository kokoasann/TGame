#include "stdafx.h"
#include "GameData.h"

Monster* g_mons[64];
int g_buddyCount = 0;
int g_enemyCount = 0;
int g_monsCount = 0;
int g_meNum = 0;
int g_meTeam = 0;

void GameData::deletemons(Monster * mon)
{
	int mop = 0;
	for (int i = 0;i < g_monsCount;i++)
	{
		Monster* gmon = g_mons[i];
		if (gmon == nullptr)
			break;
		if (gmon == mon)
			mop = i;
		for (auto ac : gmon->Getactions())
		{
			if (ac->Gettarget() == mon)
				ac->Settarget(nullptr);
		}
	}

	g_monsCount--;
	for (int i = mop; i < g_monsCount+1; i++)
	{
		g_mons[i] = g_mons[i + 1];
		/*if(g_mons[i] != NULL)
			g_mons[i]->Setnum(i);*/
	}
	/*std::vector<Monster*>::iterator ite = std::find(g_mons.begin(), g_mons.end(), mon);
	g_mons.erase(ite);*/
}
