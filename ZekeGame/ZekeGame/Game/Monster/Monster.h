#pragma once
#include "../../Engine/character/CharacterController.h"

class MonsterAction;
class PythonBridge;
class Monster:public GameObject
{
public:
	~Monster();

	bool Start() override final;
	void Update() override final;

	//Monsterのアクションを実行する関数
	void execute();

	//移動するときに使う関数
	void Move();

	//回転するときに使う関数
	void Turn();

	//ノックバック時に使う関数
	void Knockback();

	//ノックバックの始まり
	//v: ノックバックするベクトル
	void StartKnockback(CVector3 v);

	//状態
	enum en_State
	{
		en_NowLoading,
		en_Execute,
		en_Dead,
	};

	//使うpythonのファイルを設定する
	//st: ファイルの名前
	void SetpyFile(const char* st)
	{
		m_pyFile = st;
	}

	//使うpythonファイルの名前を返す
	const char* GetpyFile()
	{
		return m_pyFile;
	}

	//HPを返す
	int GetHP()
	{
		return m_HP;
	}

	//ダメージ
	//d: 食らうダメージ
	void Damage(int d)
	{
		m_HP -= d;
	}

	//MPを返す
	int GetMP()
	{
		return m_MP;
	}

	//コライダーの半径を返す
	float Getradius()
	{
		return m_radius;
	}

	//コライダーの高さを返す
	float Getheight()
	{
		return m_height;
	}

	//現在のポジションを返す
	CVector3 Getpos()
	{
		return m_pos;
	}

	//ポジションを設定する
	//v: 設定するポジション
	void Setpos(CVector3 v)
	{
		m_pos = v;
	}

	//スピードを返す
	CVector3 Getspeed()
	{
		return m_movespeed;
	}

	//スピードを設定する
	//v: スピードベクトル
	void Setspeed(CVector3 v)
	{
		m_oldmovespeed = m_movespeed;
		m_movespeed = v;
	}

	//今歩いているかを設定する
	void Setiswalk(bool b)
	{
		m_iswalk = b;
	}

	//チームを返す
	int Getteam()
	{
		return m_team;
	}

	//チームを設定する
	//t: チーム
	void Setteam(int t)
	{
		m_team = t;
	}

	//numを返す
	int Getnum()
	{
		return m_num;
	}

	//numを設定する
	//num: num
	void Setnum(int num)
	{
		m_num = num;
	}

	//これいらない
	Monster* Getmon()
	{
		return this;
	}

	//アクションを加えるときに使う
	//ma: モンスターアクション
	void AddAction(MonsterAction* ma);

	//行っている・行う予定のアクションを返す
	std::vector<MonsterAction*> Getactions()
	{
		return m_actions;
	}

	//アニメーションさせるときは必ずこいつらを使うこと。
	void anim_idle();
	void anim_walk();
	void anim_atack();
	void anim_defense();
	void anim_recovery();

	//アニメーションの状態
	enum anim
	{
		en_idle,
		en_walk,
		en_atack,
		en_defense,
		en_recovery,
	};

protected:
	const char* m_pyFile = NULL;				//使うpythonファイルの名前
	int m_ID = 0;								//モンスターの種類を判断するためのID
	int m_num = 0;								//背番号みたいな感じ
	int m_team = 0;								//チーム番号

	CharacterController m_cc;					//キャラコン
	float m_radius = 0.0f;						//半径
	float m_height = 0.0f;						//高さ
	SkinModelRender* m_smr = nullptr;			//スキンモデルレンダー
	int m_HP = 0;								//HP
	int m_MP = 0;								//MP
	float m_gravity = 50.0f;					//重力
	CVector3 m_movespeed = CVector3::Zero();	//ムーブスピード
	CVector3 m_oldmovespeed = CVector3::Zero();	//古のムーブスピード
	bool m_iswalk = false;						//
	bool m_isKnockback = false;					//
	CVector3 m_vKnockback = CVector3::Zero();	//
	CVector3 m_vSubKnock = CVector3::Zero();
	CVector3 m_pos = CVector3::Zero();			//ポジション
	CQuaternion m_rot = CQuaternion::Identity();//回転

	PythonBridge* m_PB;
	std::vector<MonsterAction*> m_actions;		//使うアクション
	en_State m_state = en_NowLoading;
	bool isLoading = false;

	int m_AnimNum = 0;							//アニメーションの個数

	float m_time = 0.0f;
};