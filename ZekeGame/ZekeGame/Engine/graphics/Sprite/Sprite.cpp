#include "stdafx.h"
#include "Sprite.h"
#include "SpBuffer.h"

struct SSimpleVertex {
	CVector4 pos;
	CVector2 tex;
};

const CVector2	Sprite::DEFAULT_PIVOT = { 0.5f, 0.5f };

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
	if (m_vertexBuffer != NULL) {
		m_vertexBuffer->Release();
	}
	if (m_indexBuffer != NULL) {
		m_indexBuffer->Release();
	}
	if (m_samplerState != NULL) {
		m_samplerState->Release();
	}
	if (m_texture != NULL) {
		m_texture->Release();
	}
	if (pBlendState != NULL) {
		pBlendState->Release();
	}
}
void Sprite::Update(const CVector3& trans, const CQuaternion& rot, const CVector3& scale, CVector2 pivot)
{
	CVector2 localPivot = pivot;
	localPivot.x -= 0.5f;
	localPivot.y -= 0.5f;
	localPivot.x *= -2.0f;
	localPivot.y *= -2.0f;
	CVector2 halfSize = m_size;
	halfSize.x *= 0.5f;
	halfSize.y *= 0.5f;
	CMatrix mPivotTrans;

	mPivotTrans.MakeTranslation(
		{ halfSize.x * localPivot.x, halfSize.y * localPivot.y, 0.0f }
	);
	CMatrix mTrans, mRot, mScale;
	mTrans.MakeTranslation(trans);
	mRot.MakeRotationFromQuaternion(rot);
	mScale.MakeScaling(scale);
	m_world.Mul(mPivotTrans, mScale);
	m_world.Mul(m_world, mRot);
	m_world.Mul(m_world, mTrans);
}

void Sprite::InitConstantBuffer()
{
	D3D11_BUFFER_DESC desc;

	ZeroMemory(&desc, sizeof(desc));
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.ByteWidth = (((sizeof(ConstantBuffer) - 1) / 16) + 1) * 16;
	desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	desc.CPUAccessFlags = 0;
	g_graphicsEngine->GetD3DDevice()->CreateBuffer(&desc, NULL, &m__cb);
}

void Sprite::Init(const wchar_t* texFilePath, float w, float h)
{
	m_size.x = w;
	m_size.y = h;
	InitVertexBuffer(m_vertexBuffer, w, h);
	InitIndexBuffer(m_indexBuffer);
	InitSamplerState(m_samplerState);
	m_effect.Load("Assets/shader/sprite.fx");
	wchar_t filePath[256];
	DirectX::CreateDDSTextureFromFileEx(
		g_graphicsEngine->GetD3DDevice(),
		texFilePath,
		0,

		D3D11_USAGE_DEFAULT,
		D3D11_BIND_SHADER_RESOURCE,
		0,
		0,
		false,
		nullptr,
		&m_texture
	);
	InitConstantBuffer();

	CD3D11_DEFAULT def;
	CD3D11_BLEND_DESC BlendDesc(def);
	BlendDesc.AlphaToCoverageEnable = TRUE;
	BlendDesc.IndependentBlendEnable = TRUE;
	BlendDesc.RenderTarget[0].BlendEnable = TRUE;
	BlendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	BlendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	BlendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	g_graphicsEngine->GetD3DDevice()->CreateBlendState(&BlendDesc, &pBlendState);
}

void Sprite::Draw()
{
	m_effect.BeginRender();
	unsigned int vertexSize = sizeof(SVertex);
	unsigned int offset = 0;
	GraphicsEngine* ge = g_graphicsEngine;
	ge->GetD3DDeviceContext()->IASetVertexBuffers(
		0,
		1,
		&m_vertexBuffer,
		&vertexSize,
		&offset
	);
	ge->GetD3DDeviceContext()->IASetIndexBuffer(
		m_indexBuffer,
		DXGI_FORMAT_R32_UINT,
		0
	);


	float blendFactor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	g_graphicsEngine->GetD3DDeviceContext()->OMSetBlendState(pBlendState, blendFactor, 0xffffffff);
	g_graphicsEngine->GetD3DDeviceContext()->PSSetShaderResources(0, 1, &m_texture);
	g_graphicsEngine->GetD3DDeviceContext()->PSSetSamplers(0, 1, &m_samplerState);

	ConstantBuffer cb;
	cb.WVP = m_world;
	cb.WVP.Mul(cb.WVP, camera2d->GetViewMatrix());
	cb.WVP.Mul(cb.WVP, camera2d->GetProjectionMatrix());
	ge->GetD3DDeviceContext()->UpdateSubresource(m__cb, 0, NULL, &cb, 0, 0);
	ge->GetD3DDeviceContext()->VSSetConstantBuffers(0, 1, &m__cb);
	ge->GetD3DDeviceContext()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	ge->GetD3DDeviceContext()->DrawIndexed(
		6,
		0,
		0
	);
}
