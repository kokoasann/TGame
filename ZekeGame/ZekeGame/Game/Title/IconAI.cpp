#include "stdafx.h"
#include "IconAI.h"
#include "../GameCursor.h"

IconAI::~IconAI()
{
	DeleteGO(m_frame);
	DeleteGO(m_dummy);
}

bool IconAI::Start()
{
	
	return true;
}

void IconAI::init(const wchar_t * py,int num,GameCursor* cursor)
{
	m_cursor = cursor;
	m_py = py;
	m_num = num;
	m_frame = NewGO<SpriteRender>(1, "sp");
	if (((m_num + 1) % 2) == 0)
		m_frame->Init(L"Assets/sprite/ai_even.dds", 372, 77);
	else
		m_frame->Init(L"Assets/sprite/ai_odd.dds", 372, 77);
	m_dummy = NewGO<SpriteRender>(0, "sp");
	m_dummy->Init(nullptr, 372, 77, true);
}

void IconAI::Update()
{
	m_isClick = false;
	m_dummy->SetCollisionTarget(m_cursor->GetCursor());
	if (m_dummy->isCollidingTarget())
	{
		if (!m_issel)
		{
			m_frame->Init(L"Assets/sprite/ai_sel.dds", 372, 77);
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
			if (((m_num + 1) % 2) == 0)
				m_frame->Init(L"Assets/sprite/ai_even.dds", 372, 77);
			else
				m_frame->Init(L"Assets/sprite/ai_odd.dds", 372, 77);
			m_issel = false;
		}
	}
}

void IconAI::PostRender()
{
	m_font.Begin();

	m_font.End();
}

void IconAI::Setpos(CVector3 pos)
{
	m_frame->SetPosition(pos);
	m_dummy->SetPosition(pos);
}

CVector3 IconAI::Getpos()
{
	return m_frame->GetPosition();
}
