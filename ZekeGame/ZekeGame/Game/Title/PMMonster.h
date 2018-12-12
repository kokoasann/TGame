#pragma once
#include "../GameData.h"
class GameCursor;
class MonsterSelect;
class AISelect;
class PMMonster :public GameObject
{
public:
	~PMMonster();
	PMMonster();
	bool Start() override;
	void init(CVector3 pos);
	void Update() override;
	void ChengeImage(const wchar_t* path,int monid);
	void SetPython(const wchar_t* py);
	void PostRender() override;

	int GetMonsterID()
	{
		return (int)m_monid;
	}
	int GetAI()
	{
		return m_selAI;
	}
private:
	MonsterID m_monid = enTest;
	int m_selAI = 0;
	GameCursor* m_cursor = nullptr;
	MonsterSelect* m_ms = nullptr;
	AISelect* m_ais = nullptr;

	SpriteRender* m_frame = nullptr;
	bool m_issel = false;
	SpriteRender* m_mon = nullptr;

	bool m_ismonsel = false;

	wchar_t m_python[16] = L"testBrain";
	CFont font;
};