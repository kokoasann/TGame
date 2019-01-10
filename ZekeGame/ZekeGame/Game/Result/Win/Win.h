#pragma once

class ResultCamera;
class Win:public GameObject
{
public:
	Win(int team);
	Win();
	~Win();
	void init(int team);
	bool Start();
	void Update();

	void MonsterSet();
	void CameraSet();

	
private:
	ResultCamera* m_cam = nullptr;
	int m_team = 0;
	SpriteRender* m_sr = nullptr;
};