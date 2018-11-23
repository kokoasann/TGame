#pragma once

class Monster;
class MonsterAction:public GameObject
{
public:
	//アクションの仮想関数。これを継承したアクションは基本的にこれだけを使う
	//me: アクションを使うもんすたー
	virtual bool Action(Monster* me) { return false; };
	
	//アクションを行う対象のモンスターの設定をする
	//num: 対象モンスターのnum
	void Settarget(int num);
	//void Resettarget();

	//直接モンスターを設定する
	//mon: 対象モンスター
	void Settarget(Monster* mon)
	{
		m_target = mon;
	}

	//対象モンスターを返す
	Monster* Gettarget()
	{
		return m_target;
	}
protected:
	int m_ActionId = 0;				//アクションのID
	int m_targetNum = 0;			//ターゲットのnum
	Monster* m_me = nullptr;		//使うもんすたー
	Monster* m_target = nullptr;	//ターゲット
};