#include "stdafx.h"
#include "IconMon.h"
#include "../GameCursor.h"

IconMon::~IconMon()
{
	DeleteGO(m_frame);
	DeleteGO(m_mon);
}

bool IconMon::Start()
{
	//m_frame->SetPivot({ 0,1 });
	return true;
}

void IconMon::init(const wchar_t * path, GameCursor* cursor)
{
	m_cursor = cursor;
	m_mon = NewGO<SpriteRender>(5, "sp");
	m_mon->Init(path,128,128,true);
	m_frame = NewGO<SpriteRender>(4, "sp");
	m_frame->Init(L"Assets/sprite/mon_none.dds", 128, 128);
}

void IconMon::Update()
{
	m_isClick = false;
	m_mon->SetCollisionTarget(m_cursor->GetCursor());
	if (m_mon->isCollidingTarget())
	{
		if (!m_issel)
		{
			m_frame->Init(L"Assets/sprite/mon_frame.dds", 128, 128);
			m_issel = true;
		}
		if (Mouse::isTrigger(enLeftClick))
		{
			m_isClick = true;
		}
	}
	else
	{
		if (m_issel)
		{
			m_frame->Init(L"Assets/sprite/mon_none.dds", 128, 128);
			m_issel = false;
		}
	}
}

void IconMon::Setpos(CVector3 pos)
{
	m_frame->SetPosition(pos);
	m_mon->SetPosition(pos);
}

CVector3 IconMon::Getpos()
{
	return m_mon->GetPosition();
}
