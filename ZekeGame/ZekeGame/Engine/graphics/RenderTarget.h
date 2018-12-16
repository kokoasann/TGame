#pragma once
class RenderTarget
{
public:
	RenderTarget();
	~RenderTarget();
	//tex weight, text hight
	void Create(unsigned int w, unsigned int h, DXGI_FORMAT texFormat);


	ID3D11RenderTargetView* GetRenderTargetView() {
		return m_renderTargetView;
	}

	ID3D11DepthStencilView* GetDepthStencilView() {
		return m_depthStencilView;
	}

	ID3D11ShaderResourceView* GetRenderTargetSRV() {
		return m_renderTargetSRV;
	}

private:
	void ReleaseRenderTarget();
	ID3D11RenderTargetView* m_renderTargetView = nullptr;
	ID3D11DepthStencilView* m_depthStencilView = nullptr;
	ID3D11Texture2D* m_depthStencilTex = nullptr;
	ID3D11ShaderResourceView* m_renderTargetSRV = nullptr;
	ID3D11Texture2D* m_renderTargetTex = nullptr;
};

