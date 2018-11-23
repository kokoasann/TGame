#pragma once

//これはテンプレートこれをコピーすると楽かもね？

#include "../MonsterAction.h"

class Monster;

//ちゃんとクラス名は変えようね？
class Act_TEMP :public MonsterAction
{
public:
	bool Action(Monster* me) override;
private:
};