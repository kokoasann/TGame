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
	m_font.Draw();
	m_font.End();
}

void FontRender::Init(
	wchar_t* const text,
	CVector3 pos,
	CQuaternion rot,
	CVector4 col,
	float scale,
	CVector2 pivot
	) {

}