#include "stdafx.h"
#include "PMMonster.h"
//#include "../GameData.h"
#include "../GameCursor.h"
#include "MonsterSelect.h"
#include "AISelect.h"

PMMonster::~PMMonster()
{
	DeleteGO(m_mon);
}

PMMonster::PMMonster()
{
	m_mon = NewGO<SpriteRender>(0, "sp");
	m_mon->Init(L"Assets/sprite/mon_none.dds", 128, 128,true);
}

bool PMMonster::Start()
{
	m_cursor = FindGO<GameCursor>("cursor");
	return true;
}

void PMMonster::init(CVector3 pos)
{
	m_mon->SetPosition(pos);
}

void PMMonster::Update()
{
	m_mon->SetCollisionTarget(m_cursor->GetCursor());
	if (m_mon->isCollidingTarget())
	{
		if (Mouse::isTrigger(enLeftClick))
		{
			m_ms = NewGO<MonsterSelect>(0, "monsterselect");
			m_ais = NewGO<AISelect>(0, "aiselect");
			m_ms->init(this);
			m_ais->init(this);
		}
	}
}

void PMMonster::ChengeImage(const wchar_t* path)
{
	m_mon->Init(path, 128, 128);
}

void PMMonster::SetPython(const wchar_t * py)
{
	for (int i = 0; i < 16; i++)
	{
		m_python[i] = py[i];
		if (py[i] == L'\0')
		{
			break;
		}
		else if (i == 15)
		{
			m_python[i - 1] = L'~';
			m_python[i] = L'\0';
		}
	}
}

void PMMonster::PostRender()
{
	font.Begin();

	CVector3 spos = m_mon->GetPosition();
	CVector2 pos;
	pos.x = spos.x-90;
	pos.y = spos.y-68;

	font.Draw(m_python, pos);

	font.End();
}
