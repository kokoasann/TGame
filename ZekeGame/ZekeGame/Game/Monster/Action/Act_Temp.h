#pragma once

//����̓e���v���[�g������R�s�[����Ɗy�����ˁH

#include "../MonsterAction.h"

class Monster;

//�����ƃN���X���͕ς��悤�ˁH
class Act_TEMP :public MonsterAction
{
public:
	bool Action(Monster* me) override;
private:
};