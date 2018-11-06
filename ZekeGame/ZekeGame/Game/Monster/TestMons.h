#pragma once

class TestMons :public GameObject, Monster
{
public:
	bool Start() override;
	void Update() override;

private:
};