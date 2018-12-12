#pragma once
class FontRender : public GameObject
{
public:
	FontRender();
	~FontRender();
	bool Start() override;
	void Update() override;
	void PostRender() override;

	void Init(const wchar_t* text, CVector2 pos, float rot, CVector4 col, float scale, CVector2 pivot);

	void SetPosition(CVector2 pos) {
		m_pos = pos;
	}
	void SetRotation(float rot) {
		m_rot = rot;
	}
	void SetColor(CVector4 col) {
		m_color = col;
	}
private:
	CFont m_font;
	wchar_t  m_text[256];
	//wchar_t * m_returnString;
	CVector2 m_pos = CVector2::Zero();
	//CQuaternion m_rot = CQuaternion::Identity();
	CVector4 m_color = CVector4::White;
	float m_scale = 1.f;
	float m_rot = 0.f;
	CVector2 m_pivot = { 0.5f,0.5f };
};

