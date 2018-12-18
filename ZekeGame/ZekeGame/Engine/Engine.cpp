#include "stdafx.h"
#include "Engine.h"
#include "Engine/FPSCounter.h"

CFPSCounter* FPS = nullptr;
NetworkLogic* m_network = nullptr;
int nNotch = 0;

Engine::Engine()
{
}


Engine::~Engine()
{
}

void Engine::Init(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPWSTR lpCmdLine,
	int nCmdShow) {
	//SetCurrentDirectory("Resource");
	InitWindow(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Game");
	IGameObjectManager().Init(32);
	FPS = new CFPSCounter(10);
}

void Engine::Release() {
	delete g_graphicsEngine;
	delete FPS;
}

void Engine::Update() {
	for (auto& pad : g_pad) {
		pad.Update();
	}

	Mouse::UpdateMouseInput();

	if (m_network != nullptr) {
		m_network->Update();
	}

	IGameObjectManager().Execute();
	//output frame late to debug message
	char message[256];
	float fps = FPS->GetFPS();
	sprintf_s(message, "%f\n", fps);
	//OutputDebugStringA(message);
}

void Engine::CreateNetworkSystem() {
	if (m_network == nullptr) {
		m_network = new NetworkLogic;
		m_network->Start();
	}
}

void Engine::DestroyNetworkSystem() {
	if (m_network != nullptr) {
		m_network->Disconnect();
		delete m_network;
		m_network = nullptr;
	}
}

void Engine::GameRoop() {
	while (DispatchWindowMessage()) {
		Update();
	}
}

void Engine::Final() {
	Release();
}

