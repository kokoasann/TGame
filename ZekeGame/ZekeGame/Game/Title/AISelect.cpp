#include "stdafx.h"
#include "AISelect.h"
#include <string>
#include "pvpModeSelect.h"
#include "../GameCursor.h"

AISelect::~AISelect()
{
}

bool AISelect::Start()
{
	m_cursor = FindGO<GameCursor>("cursor");

	m_back = NewGO<SpriteRender>(0, "sp");
	m_back->Init(L"Assets/sprite/ai_main.dds", 1280, 720,true);
	
	m_ppms = FindGO<PvPModeSelect>("pvp");
	int count = m_ppms->GetFiles().size();

	CVector3 pos = { -640,355,0 };
	for (int i = 0; i < count; i++)
	{
		SpriteRender* sp = NewGO<SpriteRender>(0, "sp");
		if (((i + 1) % 2) == 0)
			sp->Init(L"Assets/sprite/ai_even.dds", 372, 77,true);
		else
			sp->Init(L"Assets/sprite/ai_odd.dds", 372, 77,true);
		sp->SetPivot({ 0,1 });
		sp->SetPosition(pos);
		pos.y -= 82;
		m_AIs.push_back(sp);
	}
	return true;
}

void AISelect::init(PMMonster * pmm)
{
}

void AISelect::Update()
{
	for (auto sp : m_AIs)
	{
		sp->SetCollisionTarget(m_cursor->GetCursor());
		if (sp->isCollidingTarget())
		{
			if (Mouse::isTrigger(enLeftClick))
			{
				
			}
		}
	}
}

void AISelect::PostRender()
{
	font.Begin();

	for (int i = 0;i < m_AIs.size();i++)
	{
		CVector3 pos = m_AIs[i]->GetPosition();
		
		std::string st = m_ppms->GetFiles()[i];
		std::wstring ws = std::wstring(st.begin(), st.end());

		font.Draw(ws.c_str(), { 0,pos.y }, CVector4::White, 0, 1, { 0,1 });
	}

	font.End();
}
