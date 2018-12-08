#include "stdafx.h"
#include "MonsterSelect.h"

bool MonsterSelect::Start()
{
	m_back = NewGO<SpriteRender>(0, "sp");
	m_back->Init(L"Assets/sprite/mon_back.dds", m_backsize.x * 5, m_backsize.y * 7);
	m_back->SetPosition({ 10,210,-100 });


	return true;
}

void MonsterSelect::Update()
{
}
