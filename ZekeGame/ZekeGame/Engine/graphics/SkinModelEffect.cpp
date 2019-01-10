#include "stdafx.h"
#include "Engine/graphics/SkinModelEffect.h"
#include "Engine/graphics/SkinModelShaderConst.h"

void __cdecl ModelEffect::Apply(ID3D11DeviceContext* deviceContext)
{
	/*deviceContext->VSSetShader((ID3D11VertexShader*)m_pVSShader->GetBody(), NULL, 0);
	deviceContext->PSSetShader((ID3D11PixelShader*)m_pPSShader->GetBody(), NULL, 0);
	deviceContext->PSSetShaderResources(enSkinModelSRVReg_AlbedoTexture, 1, &m_albedoTex);*/
	//switch (m_renderMode) {
	//case enRenderMode_Normal: {
	//	//�ʏ�`��B
	//	//�V�F�[�_�[��K�p����B
	//	deviceContext->VSSetShader((ID3D11VertexShader*)m_vsShader.GetBody(), NULL, 0);
	//	deviceContext->PSSetShader((ID3D11PixelShader*)m_psShader.GetBody(), NULL, 0);
	//	//todo �V�F�[�_�[���\�[�X�r���[����C�ɐݒ肷��B
	//	auto srv = IGameObjectManager().GetShadowMap()->GetShadowMapSRV();

	//	ID3D11ShaderResourceView* srvArray[] = {
	//		m_albedoTexture,							//�A���x�h�e�N�X�`���B
	//		srv
	//	};
	//	deviceContext->PSSetShaderResources(0, 2, srvArray);
	//}break;
	//case enRenderMode_CreateShadowMap:
	//	//�V���h�E�}�b�v�����B
	//	deviceContext->VSSetShader((ID3D11VertexShader*)m_vsShadowMap.GetBody(), NULL, 0);
	//	deviceContext->PSSetShader((ID3D11PixelShader*)m_psShadowMap.GetBody(), NULL, 0);
	//	break;
	//}
	//TODO : renderMode�̍X�V
	if (m_renderMode == enRenderMode_CreateShadowMap) {
		deviceContext->VSSetShader((ID3D11VertexShader*)m_vsShadowMap.GetBody(), NULL, 0);
		deviceContext->PSSetShader((ID3D11PixelShader*)m_psShadowMap.GetBody(), NULL, 0);
	}
	else{
		deviceContext->VSSetShader((ID3D11VertexShader*)m_pVSShader->GetBody(), NULL, 0);
		deviceContext->PSSetShader((ID3D11PixelShader*)m_pPSShader->GetBody(), NULL, 0);
		deviceContext->PSSetShaderResources(enSkinModelSRVReg_AlbedoTexture, 1, &m_albedoTex);
		deviceContext->PSSetShaderResources(2, 1, &m_shadowMapSRV);
	}
}