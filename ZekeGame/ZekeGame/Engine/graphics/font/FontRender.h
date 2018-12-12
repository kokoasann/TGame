#pragma once
class FontRender : public GameObject
{
public:
	FontRender();
	~FontRender();
	bool Start() override;
	void Update() override;
	void PostRender() override;

	void Init(wchar_t* const text, CVector3 pos, CQuaternion rot, CVector4 col, float scale, CVector2 pivot);

	void SetPosition(CVector3 pos) {
		m_pos = pos;
	}
	void SetRotation(CQuaternion rot) {
		m_rot = rot;
	}
	void SetColor(CVector4 col) {
		m_color = col;
	}
private:
	CFont m_font;
	CVector3 m_pos = CVector3::Zero();
	CQuaternion m_rot = CQuaternion::Identity();
	CVector4 m_color = CVector4::White;
};

