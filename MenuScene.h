#pragma once
class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene();

	Enemy* enemy;
	Player player;
	Monster monster;


public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();

	void Pattern1();
	void Pattern2();
	void Pattern3();
	void Pattern4();
	void Pattern5();
};

