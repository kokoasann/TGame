#include "stdafx.h"
#include "PMMonster.h"
#include "../GameCursor.h"

PMMonster::~PMMonster()
{
}

PMMonster::PMMonster()
{
	m_mon = NewGO<SpriteRender>(0, "sp");
	m_mon->Init(L"Assets/sprite/mon_none.dds", 128, 128);
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
		if()
	}
}

void PMMonster::ChengeImage(const wchar_t* path)
{
	m_mon->Init(path, 128, 128);
	for (int i = 0; i < 16; i++)
	{
		m_python[i] = path[i];
		if (path[i] == L'\0')
		{
			break;
		}
		else if (i == 15)
		{
			m_python[i-1] = L'c';
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
