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
	//	//通常描画。
	//	//シェーダーを適用する。
	//	deviceContext->VSSetShader((ID3D11VertexShader*)m_vsShader.GetBody(), NULL, 0);
	//	deviceContext->PSSetShader((ID3D11PixelShader*)m_psShader.GetBody(), NULL, 0);
	//	//todo シェーダーリソースビューを一気に設定する。
	//	auto srv = IGameObjectManager().GetShadowMap()->GetShadowMapSRV();

	//	ID3D11ShaderResourceView* srvArray[] = {
	//		m_albedoTexture,							//アルベドテクスチャ。
	//		srv
	//	};
	//	deviceContext->PSSetShaderResources(0, 2, srvArray);
	//}break;
	//case enRenderMode_CreateShadowMap:
	//	//シャドウマップ生成。
	//	deviceContext->VSSetShader((ID3D11VertexShader*)m_vsShadowMap.GetBody(), NULL, 0);
	//	deviceContext->PSSetShader((ID3D11PixelShader*)m_psShadowMap.GetBody(), NULL, 0);
	//	break;
	//}
	//TODO : renderModeの更新
	if (m_renderMode == enRenderMode_CreateShadowMap) {
			deviceContext->VSSetShader((ID3D11VertexShader*)m_vsShadowMap.GetBody(), NULL, 0);
			deviceContext->PSSetShader((ID3D11PixelShader*)m_psShadowMap.GetBody(), NULL, 0);
	}
	else{
		deviceContext->VSSetShader((ID3D11VertexShader*)m_pVSShader->GetBody(), NULL, 0);
		deviceContext->PSSetShader((ID3D11PixelShader*)m_pPSShader->GetBody(), NULL, 0);
		deviceContext->PSSetShaderResources(enSkinModelSRVReg_AlbedoTexture, 1, &m_albedoTex);
	}
}