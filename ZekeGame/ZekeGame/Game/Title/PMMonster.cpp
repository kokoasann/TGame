#include "stdafx.h"
#include "PMMonster.h"
//#include "../GameData.h"
#include "../GameCursor.h"
#include "MonsterSelect.h"
#include "AISelect.h"

PMMonster::~PMMonster()
{
	DeleteGO(m_frame);
	DeleteGO(m_mon);
}

PMMonster::PMMonster()
{
	m_mon = NewGO<SpriteRender>(2, "sp");
	m_mon->Init(L"Assets/sprite/mon_one.dds", 128, 128,true);
	m_frame = NewGO<SpriteRender>(1, "sp");
	m_frame->Init(L"Assets/sprite/mon_none.dds", 128, 128);
}

bool PMMonster::Start()
{
	m_cursor = FindGO<GameCursor>("cursor");
	return true;
}

void PMMonster::init(int num,CVector3 pos)
{
	m_num = num;
	m_mon->SetPosition(pos);
	m_frame->SetPosition(pos);
}

void PMMonster::Update()
{
	if (m_ismonsel && Mouse::isTrigger(enRightClick))
	{
		DeleteGO(m_ms);
		DeleteGO(m_ais);
		m_ismonsel = false;
	}

	/*CVector3 v = m_cursor->GetCursor();
	v -= m_mickey;
	if (v.Length() < 0.1f)
	{
		return;
	}*/

	bool isothersel = false;
	bool issel = false;
	QueryGOs<PMMonster>("pmm", [&](PMMonster* pmm)->bool
	{
		if (pmm->isMonSel())
		{
			isothersel = true;
			return false;
		}
		if (!issel && pmm->isSelect() && pmm != this)
		{
			issel = true;
		}
		return true;
	});
	if (isothersel)
		return;
	m_mon->SetCollisionTarget(m_cursor->GetCursor());
	
	if (!m_ismonsel && m_mon->isCollidingTarget())
	{
		if (!m_issel)
		{
			m_frame->Init(L"Assets/sprite/mon_frame.dds", 128, 128);
			m_issel = true;
		}
		if (Mouse::isTrigger(enLeftClick))
		{
			m_ms = NewGO<MonsterSelect>(0, "monsterselect");
			m_ais = NewGO<AISelect>(0, "aiselect");
			m_ms->init(this);
			m_ais->init(this);
			m_ismonsel = true;
		}

	}
	else
	{
		if (m_issel && issel)
		{
			m_frame->Init(L"Assets/sprite/mon_none.dds", 128, 128);
			m_issel = false;
		}
	}
	

}

void PMMonster::ChengeImage(const wchar_t* path, int monid)
{
	m_mon->Init(path, 128, 128);
	m_monid = (MonsterID)monid;
}

void PMMonster::SetPython(const wchar_t * py,int num)
{
	m_selAI = num;
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

void PMMonster::yesSelect()
{
	m_issel = true;
	m_frame->Init(L"Assets/sprite/mon_frame.dds", 128, 128);
}

void PMMonster::notSelect()
{
	m_issel = true;
	m_frame->Init(L"Assets/sprite /mon_none.dds", 128, 128);
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
