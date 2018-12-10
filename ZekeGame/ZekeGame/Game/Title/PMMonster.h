#pragma once

class GameCursor;
class PMMonster :public GameObject
{
public:
	~PMMonster();
	PMMonster();
	bool Start() override;
	void init(CVector3 pos);
	void Update() override;
	void ChengeImage(const wchar_t* path);
	void PostRender() override;
private:
	GameCursor* m_cursor = nullptr;

	SpriteRender* m_mon = nullptr;

	wchar_t m_python[16] = L"testBrain";
	CFont font;
};