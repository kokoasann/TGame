#pragma once

#include "Engine/graphics/Shader.h"

/*!
*@brief	���f���G�t�F�N�g�B
*/
class ModelEffect : public DirectX::IEffect {
protected:
	std::wstring m_materialName;	
	Shader* m_pVSShader = nullptr;
	Shader* m_pPSShader = nullptr;
	Shader m_vsShader;
	Shader m_psShader;
	bool isSkining;
	ID3D11ShaderResourceView* m_albedoTex = nullptr;

public:
	ModelEffect(const char* psmain, const char* vsmain)
	{
		m_psShader.Load("Assets/shader/model.fx", psmain, Shader::EnType::PS);
		m_pPSShader = &m_psShader;
	}
	virtual ~ModelEffect()
	{
		if (m_albedoTex) {
			m_albedoTex->Release();
		}
	}
	void __cdecl Apply(ID3D11DeviceContext* deviceContext) override;

	void __cdecl GetVertexShaderBytecode(void const** pShaderByteCode, size_t* pByteCodeLength) override
	{
		*pShaderByteCode = m_vsShader.GetByteCode();
		*pByteCodeLength = m_vsShader.GetByteCodeSize();
	}
	void SetAlbedoTexture(ID3D11ShaderResourceView* tex)
	{
		m_albedoTex = tex;
	}
	void SetMatrialName(const wchar_t* matName)
	{
		m_materialName = matName;
	}

	bool EqualMaterialName(const wchar_t* name) const
	{
		return wcscmp(name, m_materialName.c_str()) == 0;
	}

};
/*!
*@brief
*  �X�L���Ȃ����f���G�t�F�N�g�B
*/
class NonSkinModelEffect : public ModelEffect {
public:
	NonSkinModelEffect(const char* psmain, const char* vsmain) : ModelEffect(psmain,vsmain)
	{
		m_vsShader.Load("Assets/shader/model.fx", vsmain, Shader::EnType::VS);
		m_pVSShader = &m_vsShader;
		isSkining = false;
	}
	int n;
};
/*!
*@brief
*  �X�L�����f���G�t�F�N�g�B
*/
class SkinModelEffect : public ModelEffect {
public:
	SkinModelEffect(const char* psmain, const char* vsmain) : ModelEffect(psmain,vsmain)
	{
		wchar_t hoge[256];
		GetCurrentDirectoryW(256, hoge);
		m_vsShader.Load("Assets/shader/model.fx", vsmain, Shader::EnType::VS);
		m_pVSShader = &m_vsShader;
		isSkining = true;
	}
};

/*!
*@brief
*  �G�t�F�N�g�t�@�N�g���B
*/
class SkinModelEffectFactory : public DirectX::EffectFactory {
public:
	SkinModelEffectFactory(ID3D11Device* device, const char* psmain, const char* vsmain) :
		m_psmain(psmain),
		m_vsmain(vsmain),
		EffectFactory(device) {}
	std::shared_ptr<DirectX::IEffect> __cdecl CreateEffect(const EffectInfo& info, ID3D11DeviceContext* deviceContext)override
	{
		std::shared_ptr<ModelEffect> effect;
		if (info.enableSkinning) {
			//�X�L�j���O����B
			effect = std::make_shared<SkinModelEffect>(m_psmain,m_vsmain);
		}
		else {
			//�X�L�j���O�Ȃ��B
			effect = std::make_shared<NonSkinModelEffect>(m_psmain, m_vsmain);
		}
		effect->SetMatrialName(info.name);
		if (info.diffuseTexture && *info.diffuseTexture)
		{
			ID3D11ShaderResourceView* texSRV;
			DirectX::EffectFactory::CreateTexture(info.diffuseTexture, deviceContext, &texSRV);
			effect->SetAlbedoTexture(texSRV);
		}
		return effect;
	}

	void __cdecl CreateTexture(const wchar_t* name, ID3D11DeviceContext* deviceContext, ID3D11ShaderResourceView** textureView) override
	{
		return DirectX::EffectFactory::CreateTexture(name, deviceContext, textureView);
	}
	const char* m_psmain;
	const char* m_vsmain;
};
