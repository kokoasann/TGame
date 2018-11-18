#pragma once

//�V�[���N���X�݂����ȕ�
//BaseView���p�����āA�����ŃI�[�o���C�h�������̂�LoadBalancingListener����Ă�
class TestView : public BaseView
{
public:
	TestView();
	~TestView();
	void SetLBC(ExitGames::LoadBalancing::Client* lbc, LoadBalancingListener* lbl);
	virtual void updateState(int state, const ExitGames::Common::JString& stateStr, const ExitGames::Common::JString& joinedRoomName);
private:
	ExitGames::LoadBalancing::Client* mpLbc;
	LoadBalancingListener* mpLbl;
};

