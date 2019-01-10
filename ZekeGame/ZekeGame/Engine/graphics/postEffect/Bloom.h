#pragma once
#include "../RenderTarget.h"
#include "../Shader.h"

class PostEffect;

/// <summary>
/// �u���[��
/// </summary>
class Bloom
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Bloom();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Bloom();
	/// <summary>
	/// �X�V
	/// </summary>
	void Update();
	/// <summary>
	/// �`��
	/// </summary>
	void Draw(PostEffect& postEffect);
private:
	/// <summary>
	/// �A���t�@�u�����f�B���O�̃X�e�[�g������������B
	/// </summary>
	void InitAlphaBlendState();
	/// <summary>
	/// �萔�o�b�t�@�̏������B
	/// </summary>
	void InitConstantBuffer();
	/// <summary>
	/// �V�F�[�_�[���������B
	/// </summary>
	void InitShader();
	/// <summary>
	/// �����_�����O�^�[�Q�b�g�̏������B
	/// </summary>
	void InitRenderTarget();
	/// <summary>
	/// �T���v���X�e�[�g�̏������B
	/// </summary>
	void InitSamplerState();
private:

	static const int NUM_WEIGHTS = 8;
	static const int NUM_DOWN_SAMPLING_RT = 10;
	/*!
	* @brief	�u���[�p�̃p�����[�^�o�b�t�@�B
	*@details
	* �����ύX������AAssets/shader/bloom.fx��CBBlur�̒��g���ύX����悤�ɁB
	*/
	struct SBlurParam {
		CVector4 offset;
		float weights[NUM_WEIGHTS];
	};
	float m_blurDispersion = 5.0f;		//�u���[�̕��U��B�傫������قǋ������U����B
	bool m_isEnable = false;		//!<�L���B
	RenderTarget m_luminanceRT;	//!<�P�x�𒊏o���郌���_�����O�^�[�Q�b�g�B
	RenderTarget m_combineRT;		//!<�ڂ��������p�̃����_�����O�^�[�Q�b�g�B
	RenderTarget m_downSamplingRT[NUM_DOWN_SAMPLING_RT];	//!<�_�E���T���v�����O�p�̃����_�����O�^�[�Q�b�g�B
	Shader m_vsShader;
	Shader m_psLuminance;			//!<�P�x���o�p�̃s�N�Z���V�F�[�_�[�B
	Shader m_vsXBlur;				//!<XBlur�p�̒��_�V�F�[�_�[�B
	Shader m_vsYBlur;				//!<YBlur�p�̒��_�V�F�[�_�[�B
	Shader m_psBlur;				//!<XBlur�p�̃s�N�Z���V�F�[�_�[�B
	Shader m_psCombine;			//!<�����p�̃s�N�Z���V�F�[�_�[�B
	Shader	m_copyVS;				//!<�R�s�[�p�̒��_�V�F�[�_�[�B
	Shader	m_copyPS;				//!<�R�s�[�p�̃s�N�Z���V�F�[�_�[�B
	SBlurParam m_blurParam;			//!<�u���[�p�̃p�����[�^�B
	CConstantBuffer m_cbBlur;
	ID3D11Buffer* m_blurParamCB = nullptr;
	ID3D11SamplerState* m_samplerState = nullptr;		//�T���v���X�e�[�g�B
	ID3D11BlendState* m_disableBlendState = nullptr;	//�A���t�@�u�����f�B���O�𖳌��ɂ���u�����f�B���O�X�e�[�g�B
	ID3D11BlendState* m_finalBlendState = nullptr;		//�ŏI�����p�̃u�����f�B���O�X�e�[�g�B
};
	