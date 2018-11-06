#pragma once

class MonsterAction
{
public:
	virtual bool Action() { return false; };
protected:
	int ActionId = 0;
};