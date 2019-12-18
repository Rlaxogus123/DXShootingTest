#pragma once
class Scene;

enum SCENE
{
	E_GAME,
	E_MENU,
	E_MAX
};

class Instance
{
public:
	// Render
	IDirect3DDevice9* pDevice;

	// Time
	float fdt;
	float fTimeScale;
	float fTotalTime;
	int nFPS;

	Vector2 PlayerPos;

	// Scene
	Scene* CurScene;
	Scene* SceneList[E_MAX];

	Sprite s;

public:
	Instance();
	~Instance();

private:
	static Instance* instance;

public:
	static Instance* Ins();
	void Update();
	void Render();
	void Init();
	void Destroy();

	void ChangeScene(SCENE scene);

	void DrawLine(Vector2 from, Vector2 to, Color color);
	void drawPoint(Vector2 at, Color color);
	void DrawCircle(Vector2 center, float r, Color color);
	void DrawBox(RECT colRect, Color color);

	Vector2* myNormalize(Vector2* pOut);
};


