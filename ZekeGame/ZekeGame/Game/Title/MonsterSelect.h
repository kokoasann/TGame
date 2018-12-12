#pragma once
#include "../GameData.h"
class PMMonster;
class GameCursor;
class IconMon;
class MonsterSelect :public GameObject
{
public:
	~MonsterSelect();
	bool Start();
	void init(PMMonster* pmm);
	void Update();
private:
	GameCursor* m_cursor = nullptr;

	PMMonster* m_pmm;
	MonsterID m_selmon = enTest;
	SpriteRender* m_back;
	CVector3 m_backsize = { 148,148,0 };

	std::vector<IconMon*> m_icons;
	CVector2 m_iconsize = { 128,128 };

	std::vector<std::wstring> m_paths;

	int m_monstercount = 2;
};