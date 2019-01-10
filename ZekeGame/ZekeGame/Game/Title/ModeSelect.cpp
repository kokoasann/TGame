#include "stdafx.h"
#include "ModeSelect.h"

#include "pvpModeSelect.h"
#include "AIeditModeSelect.h"

#include "../../GameCamera.h"

ModeSelect::~ModeSelect()
{
	for (auto sp : m_selection)
	{
		DeleteGO(sp);
	}
}

bool ModeSelect::Start()
{
	CVector3 vadd = { 25,100,0 };
	vadd *= -1;
	CVector3 pos = m_standardpos;
	SpriteRender* sp;

	pos = m_standardpos + vadd * enDungeon;
	sp = NewGO<SpriteRender>(0, "ui");
	sp->Init(L"Assets/Sprite/dungeonW.dds", 400, 100);
	sp->SetPosition(pos);
	m_selection.push_back(sp);

	pos = m_standardpos + vadd*enLocalpvp;
	sp = NewGO<SpriteRender>(0, "ui");
	sp->Init(L"Assets/Sprite/localpvpG.dds", 400, 100);
	sp->SetPosition(pos);
	m_selection.push_back(sp);

	pos = m_standardpos + vadd * enRandompvp;
	sp = NewGO<SpriteRender>(0, "ui");
	sp->Init(L"Assets/Sprite/randompvpG.dds", 400, 100);
	sp->SetPosition(pos);
	m_selection.push_back(sp);

	pos = m_standardpos + vadd * enAIedit;
	sp = NewGO<SpriteRender>(0, "ui");
	sp->Init(L"Assets/Sprite/AIeditG.dds", 400, 100);
	sp->SetPosition(pos);
	m_selection.push_back(sp);

	return true;
}

void ModeSelect::Update()
{
	if (g_pad[0].IsTrigger(enButtonA))
	{
		switch (m_sel)
		{
		case enDungeon:
			break;
		case enLocalpvp:
			NewGO<PvPModeSelect>(0, "pvp");
			DeleteGO(this);
			break;
		case enRandompvp:
			break;
		case enAIedit:
			NewGO<AIEditModeSelect>(0, "AIedit");
			DeleteGO(this);
			break;
		}
	}
	else if (g_pad[0].IsTrigger(enButtonDown))
	{
		if (m_sel < m_selection.size() - 1)
		{
			switch (m_sel)
			{
			case enDungeon:
				m_selection[enDungeon]->Init(L"Assets/Sprite/dungeonG.dds", 400, 100);
				m_selection[enLocalpvp]->Init(L"Assets/Sprite/localpvpW.dds", 400, 100);
				break;
			case enLocalpvp:
				m_selection[enLocalpvp]->Init(L"Assets/Sprite/localpvpG.dds", 400, 100);
				m_selection[enRandompvp]->Init(L"Assets/Sprite/randompvpW.dds", 400, 100);
				break;
			case enRandompvp:
				m_selection[enRandompvp]->Init(L"Assets/Sprite/randompvpG.dds", 400, 100);
				m_selection[enAIedit]->Init(L"Assets/Sprite/AIeditW.dds", 400, 100);
				break;
			case enAIedit:
				break;
			}
			m_sel++;
			
		}

	}
	else if (g_pad[0].IsTrigger(enButtonUp))
	{
		if (m_sel > 0)
		{
			switch (m_sel)
			{
			case enDungeon:
				break;
			case enLocalpvp:
				m_selection[enDungeon]->Init(L"Assets/Sprite/dungeonW.dds", 400, 100);
				m_selection[enLocalpvp]->Init(L"Assets/Sprite/localpvpG.dds", 400, 100);
				break;
			case enRandompvp:
				m_selection[enLocalpvp]->Init(L"Assets/Sprite/localpvpW.dds", 400, 100);
				m_selection[enRandompvp]->Init(L"Assets/Sprite/randompvpG.dds", 400, 100);
				break;
			case enAIedit:
				m_selection[enRandompvp]->Init(L"Assets/Sprite/randompvpW.dds", 400, 100);
				m_selection[enAIedit]->Init(L"Assets/Sprite/AIeditG.dds", 400, 100);
				break;
			}
			m_sel--;
		}
	}
}