#pragma once

class PMMonster;
class GameCursor;
class PvPModeSelect :public GameObject
{
public:
	~PvPModeSelect();
	bool Start() override;
	void Update() override;
	void PostRender() override;
	void LoadFiles();
private:
	CFont font;
	std::vector<std::string> m_files;
	int monai[6] = {0};
	int curpos = 0;
	bool sel = false;

	GameCursor* m_cursor;

	PMMonster* m_pmm = nullptr;
	std::vector<SpriteRender*> m_monicon;
};