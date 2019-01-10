#pragma once
#include "Effect.h"
#include "../ShaderResouceView.h"
#include "../CRenderContext.h"
#include "../CPrimitive.h"
#include "../CShader.h"
#include "../Shader.h"

class Sprite : Noncopyable
{
public:
	static const CVector2	DEFAULT_PIVOT;					//!<�s�{�b�g�B

	Sprite();
	~Sprite();
	void Init(ID3D11ShaderResourceView* srv, float w, float h);
	/*
	*@brief	�������B
	*@param	texFilePath		�e�N�X�`���̃t�@�C���p�X�B
	*@param	w				�摜�̕��B
	*@param	h				�摜�̍����B
	*/
	void Init(const wchar_t* texFilePath, float w, float h);
	/*
	*@brief	�X�V�B
	*@param[in]	trans		���s�ړ��B
	*@param[in]	rot			��]�B
	*@param[in]	scale		�g��B
	*@param[in]	pivot		��_�B
	*						0.5, 0.5�ŉ摜�̒��S����_�B
	*						0.0, 0.0�ŉ摜�̍����B
	*						1.0, 1.0�ŉ摜�̉E��B
	*						Unity��uGUI�ɏ����B
	*/
	void Update(const CVector3& trans, const CQuaternion& rot, const CVector3& scale, CVector2 pivot = { 0.5f, 0.5f });
	/*
	*@brief	�`��B
	*/
	void Draw();
	void Draww();

	struct ConstantBuffer {
		CMatrix WVP;		//���[���h�r���[�v���W�F�N�V�����s��B
	};
	ID3D11Buffer*				m_vertexBuffer = NULL;					//���_�o�b�t�@�B
	ID3D11Buffer*				m_indexBuffer = NULL;					//�C���f�b�N�X�o�b�t�@�B
	Effect						m_effect;								//�G�t�F�N�g�B�C�ɂ��Ȃ��Ă悢�B
	ID3D11ShaderResourceView*	m_texture = NULL;						//�e�N�X�`���B
	ID3D11SamplerState*			m_samplerState = NULL;					//�T���v���X�e�[�g�B
	CVector3					m_position = CVector3::Zero();			//���W�B
	CQuaternion					m_rotation = CQuaternion::Identity();	//��]
	CVector3					m_scale = CVector3::One();
	CMatrix						m_world = CMatrix::Identity();			//���[���h�s��B
	CVector2					m_size = CVector2::Zero();				//�摜�̃T�C�Y�B
	ID3D11Buffer*				m__cb = nullptr;							//�萔�o�b�t�@�B
	Shader						m_vs;									//���_�V�F�[�_�[�B
	Shader						m_ps;									//�s�N�Z���V�F�[�_�[�B
private:
	void InitCommon(float w, float h);
	/*!
	*@brief	�萔�o�b�t�@�̏������B
	*/
	void InitConstantBuffer();
	void InitVertexBuffer(float w, float h);
	void InitIndexBuffer();
	void InitSamplerState();

	ID3D11BlendState* pBlendState = NULL;
};
