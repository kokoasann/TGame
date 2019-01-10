#include "stdafx.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "CTransform.h"

void GameObjectManager::Execute()
{
	ExecuteDeleteGameObjects();

	for (GameObjectList objList : m_gameObjectListArray) {
		for (GameObject* obj : objList) {
			obj->StartWrapper();
		}
	}
	for (GameObjectList objList : m_gameObjectListArray) {
		for (GameObject* obj : objList) {
			obj->PreUpdateWrapper();
		}
	}

	for (GameObjectList objList : m_gameObjectListArray) {
		for (GameObject* obj : objList) {
			obj->UpdateWrapper();
		}
	}

	//�V���h�E�L���X�^�[��o�^�B
	//for (auto i = m_shadowCasters.begin(); i != m_shadowCasters.end(); ++i) {
	//	m_shadowMap.RegistShadowCaster(m_);
	//}
	/*for (auto& caster : m_shadowCasters) {
		m_shadowMap.RegistShadowCaster(caster);
	}*/
	//�V���h�E�}�b�v���X�V�B
	m_shadowMap.UpdateFromLightTarget(
		{ 1000.0f, 1000.0f, 1000.0f },
		{ 0.0f, 0.0f, 0.0f }
	);

	for (GameObjectList objList : m_gameObjectListArray) {
		for (GameObject* obj : objList) {
			obj->PostUpdateWrapper();
		}
	}

	m_postEffect.Update();

	//g_graphicsEngine->GetEffectEngine().Update();

	g_graphicsEngine->BegineRender();
	//�t���[���o�b�t�@�̂̃����_�����O�^�[�Q�b�g���o�b�N�A�b�v���Ă����B
	auto d3dDeviceContext = g_graphicsEngine->GetD3DDeviceContext();
	d3dDeviceContext->OMGetRenderTargets(
		1,
		&m_frameBufferRenderTargetView,
		&m_frameBufferDepthStencilView
	);
	//�r���[�|�[�g���o�b�N�A�b�v������Ă����B
	unsigned int numViewport = 1;
	d3dDeviceContext->RSGetViewports(&numViewport, &m_frameBufferViewports);
	//�V���h�E�}�b�v�Ƀ����_�����O
	m_shadowMap.RenderToShadowMap();
	//�����_�����O�^�[�Q�b�g�����C���ɕύX����B
	g_graphicsEngine->ChangeRenderTarget(&m_mainRenderTarget, &m_frameBufferViewports);
	//���C�������_�����O�^�[�Q�b�g���N���A����B
	float clearColor[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	m_mainRenderTarget.ClearRenderTarget(clearColor);
	//�����_�����O
	for (GameObjectList objList : m_gameObjectListArray) {
		for (GameObject* obj : objList) {
			obj->PreRenderWrapper();
		}
	}

	for (GameObjectList objList : m_gameObjectListArray) {
		for (GameObject* obj : objList) {
			obj->RenderWrapper();
		}
	}


	for (GameObjectList objList : m_gameObjectListArray) {
		for (GameObject* obj : objList) {
			obj->PostRenderWrapper();
		}
	}

	m_postEffect.Draw();
	//�����_�����O�^�[�Q�b�g���t���[���o�b�t�@�ɖ߂��B
	g_graphicsEngine->ChangeRenderTarget(
		m_frameBufferRenderTargetView,
		m_frameBufferDepthStencilView,
		&m_frameBufferViewports
	);
	//�h���h��
	m_copyMainRtToFrameBufferSprite.Draww();

	m_frameBufferRenderTargetView->Release();
	m_frameBufferDepthStencilView->Release();
	g_graphicsEngine->EndRender();
}

void GameObjectManager::UpdateSceneGraph()
{
	//���[���h�s����X�V�B
	for (auto transform : m_childrenOfRootTransformList) {
		transform->UpdateWorldMatrixAll();
	}
}
void GameObjectManager::ExecuteDeleteGameObjects()
{
	int preBufferNo = m_currentDeleteObjectBufferNo;
	//�o�b�t�@��؂�ւ��B
	m_currentDeleteObjectBufferNo = 1 ^ m_currentDeleteObjectBufferNo;
	for (GameObjectList& goList : m_deleteObjectArray[preBufferNo]) {
		for (GameObject* go : goList) {
			GameObjectPrio prio = go->GetPriority();
			GameObjectList& goExecList = m_gameObjectListArray.at(prio);
			auto it = std::find(goExecList.begin(), goExecList.end(), go);
			if (it != goExecList.end()) {
				//�폜���X�g���珜�O���ꂽ�B
				(*it)->m_isRegistDeadList = false;
				if ((*it)->IsNewFromGameObjectManager()) {
					delete (*it);
				}
			}
			goExecList.erase(it);
		}
		goList.clear();
	}
}
void GameObjectManager::Init(int gameObjectPrioMax)
{
	assert(gameObjectPrioMax <= GAME_OBJECT_PRIO_MAX && "�Q�[���I�u�W�F�N�g�̗D��x�̍ő吔���傫�����܂��B");
	m_gameObjectPriorityMax = static_cast<GameObjectPrio>(gameObjectPrioMax);
	m_gameObjectListArray.resize(gameObjectPrioMax);
	m_deleteObjectArray[0].resize(gameObjectPrioMax);
	m_deleteObjectArray[1].resize(gameObjectPrioMax);

	m_mainRenderTarget.Create(
		FRAME_BUFFER_W,
		FRAME_BUFFER_H,
		DXGI_FORMAT_R16G16B16A16_FLOAT
	);
	//���C�������_�����O�^�[�Q�b�g�ɕ`���ꂽ�G��
	//�t���[���o�b�t�@�ɃR�s�[���邽�߂̃X�v���C�g������������B
	m_copyMainRtToFrameBufferSprite.Init(
		m_mainRenderTarget.GetRenderTargetSRV(),
		FRAME_BUFFER_W,
		FRAME_BUFFER_H
	);
}