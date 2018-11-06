#pragma once

class MonsterAction;
class MonsterAI
{
public:
	void execute();
protected:

	std::vector<MonsterAction*> m_action;
};