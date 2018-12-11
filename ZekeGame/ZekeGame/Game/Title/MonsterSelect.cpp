#include "stdafx.h"
#include "MonsterSelect.h"
#include "PMMonster.h"
#include "../GameCursor.h"
#include <string>
//#include "../GameData.h"

#include "AISelect.h"

bool MonsterSelect::Start()
{
	m_cursor = FindGO<GameCursor>("cursor");

	m_back = NewGO<SpriteRender>(0, "sp");
	m_back->Init(L"Assets/sprite/mon_back.dds", m_backsize.x * 4, m_backsize.y * 5);
	m_back->SetPivot({ 0,1 });
	CVector3 pos = { -80,330,0 };
	m_back->SetPosition(pos);

	pos += { 10,-10,0 };
	for (int i = 0; i < m_monstercount; i++)
	{
		SpriteRender* sr = NewGO<SpriteRender>(1, "sp");
		sr->SetPivot({ 0,1 });
		std::wstring path;
		switch (i)
		{
		case enTest:
			sr->Init(L"Assets/sprite/mon_one.dds", m_iconsize.x, m_iconsize.y,true);
			path = L"Assets/sprite/mon_one.dds";
			break;
		case enUmataur:
			sr->Init(L"Assets/sprite/mon_two.dds", m_iconsize.x, m_iconsize.y, true);
			path = L"Assets/sprite/mon_two.dds";
			break;
		}
		sr->SetPosition(pos);
		if (((i+1) % 5) == 0)
		{
			pos.x = 30;
			pos.y -= 148;
		}
		else pos += {148,0, 0};
		m_mons.push_back(sr);
		m_paths.push_back(path.c_str());
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
	for(int i = 0;i < m_mons.size();i++)
	{
		SpriteRender* sp = m_mons[i];
		sp->SetCollisionTarget(m_cursor->GetCursor());
		if (sp->isCollidingTarget())
		{
			if (Mouse::isTrigger(enLeftClick))
			{
				
				m_pmm->ChengeImage(m_paths[i]);
			}

		}
	}
}
