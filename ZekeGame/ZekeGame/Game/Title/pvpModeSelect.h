#pragma once

class PvPModeSelect :public GameObject
{
public:
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

	std::vector<SpriteRender*> m_monicon;
};