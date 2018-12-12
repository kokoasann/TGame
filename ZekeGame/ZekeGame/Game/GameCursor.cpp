#include "stdafx.h"
#include "GameCursor.h"



GameCursor::~GameCursor()
{
	DeleteGO(m_cursor);
}

bool GameCursor::Start()
{
	m_cursor = NewGO<SpriteRender>(31, "cursor");
	m_cursor->Init(L"Assets/Sprite/cursor.dds", 80, 80);
	m_cursor->SetPosition(m_pos);
	m_cursor->SetPivot({ 0,1 });
	return true;
}

void GameCursor::Update()
{
	float x = g_pad[0].GetRStickXF()*10;
	float y = g_pad[0].GetRStickYF()*10;

	m_pos.x += x;

	m_pos.y += y;

	m_cursor->SetPosition(m_pos);
}
