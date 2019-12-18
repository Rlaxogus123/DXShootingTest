#include "DXUT.h"
#include "Include.h"

MenuScene::MenuScene()
{
	player.SetTexture(L"Lib.jpg", 0);
	v_node.push_back(&player);
	player.tag = L"P1";

	monster.SetTexture(L"Lib.jpg", 0);
	v_node.push_back(&monster);
	monster.tag = L"M1";
}

MenuScene::~MenuScene()
{
}

void MenuScene::Init()
{
	Scene::Enter();
}

void MenuScene::Update()
{
	D_INS->PlayerPos = player.position;

	if (DXUTIsKeyDown(VK_F3)) D_INS->ChangeScene(E_GAME);

	static float tick;
	tick += D_INS->fdt;
	
	if (tick > 0.25)
	{
		if (DXUTIsKeyDown('1')) Pattern1();
		if (DXUTIsKeyDown('2')) Pattern2();
		if (DXUTIsKeyDown('3')) Pattern3();
		if (DXUTIsKeyDown('4')) Pattern4();
		if (DXUTIsKeyDown('5')) Pattern5();

		tick = 0;
	}

	Scene::Update();
}

void MenuScene::Render()
{
	Scene::Render();
}

void MenuScene::Destroy()
{
	Scene::Exit();
}

void MenuScene::Pattern1()
{
	float angle = 0;
	for (int i = 0; i < 32; i++)
	{
		v_node.push_back(new Enemy(monster.position, 1, 200, angle));
		angle += 11.25;
	}
}

void MenuScene::Pattern2()
{
	v_node.push_back(new Enemy(monster.position, 2, 200, 0));
}

void MenuScene::Pattern3()
{
	v_node.push_back(new Enemy(monster.position, 7, 200, 0));
}

void MenuScene::Pattern4()
{
	v_node.push_back(new Enemy(monster.position, 3, 200, 0));
	v_node.push_back(new Enemy(monster.position, 4, 200, 0));
	v_node.push_back(new Enemy(monster.position, 3, 200, -180));
	v_node.push_back(new Enemy(monster.position, 4, 200, -180));

}

void MenuScene::Pattern5()
{
	v_node.push_back(new Enemy(monster.position, 5, 200, 90));
	v_node.push_back(new Enemy(monster.position, 6, 200, 90));
	v_node.push_back(new Enemy(monster.position, 5, 200, 270));
	v_node.push_back(new Enemy(monster.position, 6, 200, 270));
}

