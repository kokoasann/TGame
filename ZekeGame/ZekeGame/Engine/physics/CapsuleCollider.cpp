/*!
* @brief	�J�v�Z���R���C�_�[�B
*/

#include "stdafx.h"
#include "CapsuleCollider.h"


/*!
* @brief	�f�X�g���N�^�B
*/
CapsuleCollider::~CapsuleCollider()
{
	if (m_axis == enFbxUpAxisY) {
		delete shape;
	}
	else if (m_axis == enFbxUpAxisZ) {
		delete shapez;
	}
	else {
		delete shapex;
	}
}
