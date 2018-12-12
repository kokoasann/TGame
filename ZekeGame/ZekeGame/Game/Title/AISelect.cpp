#include "stdafx.h"
#include "AISelect.h"
#include "PMMonster.h"
#include <string>
#include "pvpModeSelect.h"
#include "../GameCursor.h"
#include "IconAI.h"

AISelect::~AISelect()
{
	DeleteGO(m_back);
	for (auto ia : m_icons)
	{
		DeleteGO(ia);
	}
}

bool AISelect::Start()
{
	m_cursor = FindGO<GameCursor>("cursor");

	m_back = NewGO<SpriteRender>(0, "sp");
	m_back->Init(L"Assets/sprite/ai_main.dds", 1280, 720,true);
	
	m_ppms = FindGO<PvPModeSelect>("pvp");
	int count = m_ppms->GetFiles().size();

	CVector3 pos = { -454,316.5f,0 };
	for (int i = 0; i < count; i++)
	{
		IconAI* ia = NewGO<IconAI>(0, "ia");
		ia->init(nullptr, i, m_cursor);
		ia->Setpos(pos);
		m_icons.push_back(ia);

		pos.y -= 82;
	}
	return true;
}

void AISelect::init(PMMonster * pmm)
{
	m_pmm = pmm;
}

void AISelect::Update()
{
	for (int i = 0;i < m_icons.size();i++)
	{
		if (m_icons[i]->isClick())
		{
			std::string st = m_ppms->GetFiles()[i];
			std::wstring ws = std::wstring(st.begin(), st.end());
			m_pmm->SetPython(ws.c_str());
		}
	}
}

void AISelect::PostRender()
{
	font.Begin();
	for (int i = 0; i < m_icons.size(); i++)
	{
		CVector3 pos = m_icons[i]->Getpos();

		std::string st = m_ppms->GetFiles()[i];
		std::wstring ws = std::wstring(st.begin(), st.end());

		font.Draw(ws.c_str(), { 0,pos.y }, CVector4::White, 0, 1, { 0,1 });
	}

	font.End();
}
