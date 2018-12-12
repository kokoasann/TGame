#include "stdafx.h"
#include "MonsterSelect.h"
#include "PMMonster.h"
#include "../GameCursor.h"
#include "IconMon.h"
#include <string>
//#include "../GameData.h"

#include "AISelect.h"

MonsterSelect::~MonsterSelect()
{
	DeleteGO(m_back);
	for (auto ic : m_icons)
	{
		DeleteGO(ic);
	}
}

bool MonsterSelect::Start()
{
	m_cursor = FindGO<GameCursor>("cursor");

	m_back = NewGO<SpriteRender>(0, "sp");
	m_back->Init(L"Assets/sprite/mon_back.dds", m_backsize.x * 4, m_backsize.y * 5);
	m_back->SetPivot({ 0,1 });
	CVector3 pos = { -80,330,0 };
	m_back->SetPosition(pos);

	pos += { 70,-70,0 };
	for (int i = 0; i < m_monstercount; i++)
	{
		IconMon* im = NewGO<IconMon>(0, "im");
		std::wstring path;
		switch (i)
		{
		case enTest:
			im->init(L"Assets/sprite/mon_one.dds",m_cursor);
			path = L"Assets/sprite/mon_one.dds";
			break;
		case enUmataur:
			im->init(L"Assets/sprite/mon_two.dds", m_cursor);
			path = L"Assets/sprite/mon_two.dds";
			break;
		}
		im->Setpos(pos);
		if (((i+1) % 5) == 0)
		{
			pos.x = 30;
			pos.y -= 148;
		}
		else pos += {148,0, 0};
		m_icons.push_back(im);
		m_paths.push_back(path);
	}

	//NewGO<AISelect>(0, "ais");
	return true;
}

void MonsterSelect::init(PMMonster * pmm)
{
	m_pmm = pmm;
	m_selmon = (MonsterID)m_pmm->GetMonsterID();
}

void MonsterSelect::Update()
{
	Mouse::GetMouseNotch();

	for (int i = 0;i < m_icons.size();i++)
	{
		if (m_icons[i]->isClick())
		{
			m_pmm->ChengeImage(m_paths[i].c_str(),i);
		}
	}
}
