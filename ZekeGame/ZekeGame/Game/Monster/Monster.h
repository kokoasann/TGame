#pragma once

class Monster:public MonsterAI
{
public:
	void execute() final override;
	enum State
	{
		NowLoading,
		Execute,
	};
protected:
	State m_state = NowLoading;
};