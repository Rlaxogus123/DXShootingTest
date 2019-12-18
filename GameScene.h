#pragma once
class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	Player player;
	Monster monster;

	Sprite spr;
	Sprite r_spr1;
	Sprite r_spr2;

	float delta;

	float fCreateBulletTime;
	float fCulBulletTime;

public:
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();

	void CreateBullet();
};

