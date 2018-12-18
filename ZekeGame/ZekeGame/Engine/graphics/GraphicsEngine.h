#pragma once

#include "CShaderResource.h"
#include "Effect\CEffectEngine.h"

class CShaderResource;
class CEffectEngine;

enum EnRenderMode {
	enRenderMode_Invalid,			//不正なレンダリングモード。
	enRenderMode_CreateShadowMap,	//シャドウマップ生成。
	enRenderMode_Normal,			//通常レンダリング。
	enRenderMode_Num,				//レンダリングモードの数。
};

class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();

	void InitDirectX(HWND hwnd);
	void Clear();
	void Release();
	CShaderResource &GetShaderResources()
	{
		return m_shaderResources;
	}

	ID3D11Device* GetD3DDevice() {
		return m_pd3dDevice;
	}
	ID3D11DeviceContext* GetD3DDeviceContext()
	{
		return m_pd3dDeviceContext;
	}
	DirectX::SpriteBatch* GetSpriteBatch() const
	{
		return m_spriteBatch.get();
	}
	DirectX::SpriteFont* GetSpriteFont() const
	{
		return m_spriteFont.get();
	}
	int GetFrameBufferWidth() const
	{
		return m_frameBufferWidth;
	}
	int GetFrameBufferHeight() const
	{
		return m_frameBufferHeight;
	}
	int Get2DSpaceScreenWidth() const
	{
		return m_2dSpaceScreenWidth;
	}
	int Get2DSpaceScreenHeight() const
	{
		return m_2dSpaceScreenHeight;
	}
	/*!
	*@brief	エフェクトエンジンの取得。
	*/
	CEffectEngine& GetEffectEngine()
	{
		return m_effectEngine;
	}

	ID3D11RenderTargetView* GetTarget() {
		return m_backBuffer;
	}

	void BegineRender();
	void EndRender();
private:
	CShaderResource m_shaderResources;
	ID3D11Device* m_pd3dDevice = NULL;
	ID3D11DeviceContext* m_pd3dDeviceContext = NULL;
	D3D_FEATURE_LEVEL m_featureLevel;
	IDXGISwapChain* m_pSwapChain = NULL;
	ID3D11RenderTargetView* m_backBuffer = NULL;
	ID3D11RasterizerState* m_rasterizerState = NULL;
	ID3D11Texture2D* m_depthStencil = NULL;
	ID3D11DepthStencilView* m_depthStencilView = NULL;
	std::unique_ptr<DirectX::SpriteBatch>	m_spriteBatch;
	std::unique_ptr<DirectX::SpriteFont>	m_spriteFont;
	CEffectEngine m_effectEngine;
	int						m_2dSpaceScreenWidth = 1280;
	int						m_2dSpaceScreenHeight = 720;
	int						m_frameBufferWidth = 0;
	int						m_frameBufferHeight = 0;
};

