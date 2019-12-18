#include "DXUT.h"
#include "Include.h"

Instance::Instance()
{
	pDevice = DXUTGetD3D9Device();
	CurScene = nullptr;

	SceneList[E_GAME] = new GameScene();
	SceneList[E_MENU] = new MenuScene();
	CurScene = SceneList[E_GAME];
	CurScene->Enter();
}

Instance::~Instance()
{
}

Instance* Instance::Ins()
{
	if (instance == nullptr)
	{
		instance = new Instance();
	}
	return instance;
}

void Instance::Init()
{
}

void Instance::Update()
{
	if (CurScene != nullptr)
		CurScene->Update();
}

void Instance::Render()
{
	if (CurScene != nullptr)
		CurScene->Render();
}

void Instance::Destroy()
{
	exit(0);
}

void Instance::ChangeScene(SCENE scene)
{
	if (SceneList[scene] != nullptr)
	{
		CurScene->Exit();
		CurScene = SceneList[scene];
		CurScene->Enter();
	}
}

void Instance::DrawLine(Vector2 from, Vector2 to, Color color)
{
	LPD3DXLINE line;
	D3DXCreateLine(pDevice, &line);
	D3DXVECTOR2 lines[] = { from, to };
	line->Begin();
	line->Draw(lines, 2, color);
	line->End();
	line->Release();
}

void Instance::drawPoint(Vector2 at, Color color)
{
	DrawLine(at, at + Vector2(0.0f, 1.0f), color);
}

void Instance::DrawCircle(Vector2 center, float r, Color color)
{
	const float step = 2 * D3DX_PI / 180;
	float angle = 0;
	for (int i = 0; i < 180; i++) {
		DrawLine(center + Vector2(r * cos(angle), r * sin(angle)),
			center + Vector2(r * cos(angle + step), r * sin(angle + step)), color);
		angle += step;
	}
}

void Instance::DrawBox(RECT colRect, Color color)
{
	D_INS->DrawLine(Vector2(colRect.left, colRect.top), Vector2(colRect.right, colRect.top), color);
	D_INS->DrawLine(Vector2(colRect.right, colRect.top), Vector2(colRect.right, colRect.bottom), color);
	D_INS->DrawLine(Vector2(colRect.right, colRect.bottom), Vector2(colRect.left, colRect.bottom), color);
	D_INS->DrawLine(Vector2(colRect.left, colRect.top), Vector2(colRect.left, colRect.bottom), color);
}

Vector2* Instance::myNormalize(Vector2* pOut)
{
	float Length = sqrt(pOut->x * pOut->x + pOut->y * pOut->y);
	pOut->x / Length;
	pOut->y / Length;

	return pOut;
}
