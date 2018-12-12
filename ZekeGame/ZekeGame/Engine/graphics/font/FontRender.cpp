#include "stdafx.h"
#include "FontRender.h"



FontRender::FontRender()
{
}


FontRender::~FontRender()
{
}

bool FontRender::Start() {
	return true;
}

void FontRender::Update() {

}

void FontRender::PostRender() {
	m_font.Begin();
	m_font.Draw(m_text, m_pos, m_color, m_rot, m_scale, m_pivot);
	m_font.End();
}

void FontRender::Init(
	const wchar_t* text,
	CVector2 pos,
	float rot,
	CVector4 col,
	float scale,
	CVector2 pivot
	) {
	//m_text = text;
	wcscpy(m_text,text);
	m_pos = pos;
	m_rot = rot;
	m_color = col;
	m_scale = scale;
	m_pivot = pivot;
}