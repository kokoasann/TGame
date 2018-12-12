#pragma once

class GameCursor;
class IconMon :public GameObject
{
public:
	~IconMon();
	bool Start();
	void init(const wchar_t* path,GameCursor* cursor);
	void Update();
	void Setpos(CVector3 pos);
	CVector3 Getpos();

	bool isClick()
	{
		return m_isClick;
	}
private:
	GameCursor* m_cursor = nullptr;
	SpriteRender* m_frame = nullptr;
	SpriteRender* m_mon = nullptr;

	bool m_isClick = false;
	bool m_issel = false;
};