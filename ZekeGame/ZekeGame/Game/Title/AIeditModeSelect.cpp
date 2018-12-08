#include "stdafx.h"
#include "AIeditModeSelect.h"

#include "ModeSelect.h"
#include "../AIEdit/AIEditMode.h"

AIEditModeSelect::~AIEditModeSelect()
{
	DeleteGO(m_spMode[0]);
	DeleteGO(m_spMode[1]);
}

bool AIEditModeSelect::Start()
{
	CVector3 basepos = { 100,100,0 };
	CVector3 addpos = { 25,100,0 };

	m_spMode[0] = NewGO<SpriteRender>(0, "Mode");
	m_spMode[0]->Init(L"Assets/sprite/easyeditW.dds", 400, 100);
	m_spMode[0]->SetPosition(basepos);
	basepos -= addpos;

	m_spMode[1] = NewGO<SpriteRender>(0, "Mode");
	m_spMode[1]->Init(L"Assets/sprite/pythoneditG.dds", 400, 100);
	m_spMode[1]->SetPosition(basepos);

	return true;
}

void AIEditModeSelect::Update()
{
	if (g_pad[0].IsTrigger(enButtonA))
	{
		switch (m_sel)
		{
		case enVisual:
			NewGO<AIEditMode>(0, "AIEM");
			DeleteGO(this);
			break;
		case enPython:
			break;
		}
	}
	else if (g_pad[0].IsTrigger(enButtonDown))
	{
		if (m_sel < 2 - 1)
		{
			switch (m_sel)
			{
			case enVisual:
				m_spMode[enVisual]->Init(L"Assets/sprite/easyeditG.dds", 400, 100);
				m_spMode[enPython]->Init(L"Assets/sprite/pythoneditW.dds", 400, 100);
				break;
			case enPython:
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
			case enVisual:
				break;
			case enPython:
				m_spMode[enVisual]->Init(L"Assets/sprite/easyeditW.dds", 400, 100);
				m_spMode[enPython]->Init(L"Assets/sprite/pythoneditG.dds", 400, 100);
				break;
			}
			m_sel--;
		}
	}
	else if (g_pad[0].IsTrigger(enButtonB))
	{
		NewGO<ModeSelect>(0, "modesel");
		DeleteGO(this);
	}
}
