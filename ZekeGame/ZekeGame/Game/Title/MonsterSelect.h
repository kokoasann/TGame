#pragma once

class MonsterSelect :public GameObject
{
public:

	bool Start();
	void Update();
private:
	SpriteRender* m_back;
	CVector2 m_backsize = { 148,148 };

	std::vector<SpriteRender*> m_mons;
	CVector2 m_iconsize = { 128,128 };
};