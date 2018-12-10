#include "stdafx.h"
#include "MonsterSelect.h"
#include "PMMonster.h"
//#include "../GameData.h"

#include "AISelect.h"

bool MonsterSelect::Start()
{
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
		switch (i)
		{
		case enTest:
			sr->Init(L"Assets/sprite/mon_one.dds", m_iconsize.x, m_iconsize.y,true);
			break;
		case enUmataur:
			sr->Init(L"Assets/sprite/mon_two.dds", m_iconsize.x, m_iconsize.y, true);
			break;
		}
		sr->SetPosition(pos);
		if (((i+1) % 5) == 0)
		{
			pos.x = 30;
			pos.y -= 148;
		}
		else pos += {148,0, 0};
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
}
