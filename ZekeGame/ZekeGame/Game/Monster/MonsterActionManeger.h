#pragma once

class MonsterAction;

//�����X�^�[�A�N�V�����̃��[�f�B���O��S���Ă���
class MonsterActionManeger:public GameObject
{
public:
	//�����X�^�[�ɋZ��������Ƃ��Ɏg�����[�_�[
	//id:		�Z��ID
	//target:	�Ώۂ̃����X�^�[
	MonsterAction* LoadAction(int id,int target);

	//TODO: �V�����Z��ǉ�����Ƃ��͂����ɂ��ǉ����悤
	enum en_action
	{
		en_Chase,
		en_Atack,
		en_Leave,
	};
private:
};