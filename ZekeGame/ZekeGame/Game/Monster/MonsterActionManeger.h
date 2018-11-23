#pragma once

class MonsterAction;

//モンスターアクションのローディングを担っている
class MonsterActionManeger:public GameObject
{
public:
	//モンスターに技を加えるときに使うローダー
	//id:		技のID
	//target:	対象のモンスター
	MonsterAction* LoadAction(int id,int target);

	//TODO: 新しい技を追加するときはここにも追加しよう
	enum en_action
	{
		en_Chase,
		en_Atack,
		en_Leave,
	};
private:
};