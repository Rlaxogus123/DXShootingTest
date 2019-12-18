#include "DXUT.h"
#include "Include.h"

GameScene::GameScene()
{
	player.SetTexture(L"Lib.jpg", 0);
	v_node.push_back(&player);
	player.tag = L"P1";

	monster.SetTexture(L"Lib.jpg", 0);
	v_node.push_back(&monster);
	monster.IsRadian = true;
	monster.tag = L"M1";

	spr.SetTexture(L"Lib.jpg", 0);
	v_node.push_back(&spr);
	spr.tag = L"P2";

	r_spr1.SetTexture(L"Lib.jpg", 0);
	r_spr1.position = { 200,200 };
	r_spr1.IsRadian = true;
	v_node.push_back(&r_spr1);
	r_spr1.tag = L"R1";

	r_spr2.SetTexture(L"Lib.jpg", 0);
	r_spr2.position = { 350,300 };
	r_spr2.IsRadian = true;
	v_node.push_back(&r_spr2);
	r_spr2.tag = L"R2";

	fCreateBulletTime = 0.2f;
	fCulBulletTime = 0;
}

GameScene::~GameScene()
{
}

void GameScene::Enter()
{
	Scene::Enter();
}

void GameScene::Update()
{
	Scene::Update();

	D_INS->PlayerPos = player.position;
	  
	if(DXUTIsKeyDown(VK_F2))
	{
		D_INS->ChangeScene(E_MENU);
	}

	if (AABB(L"P1", L"P2"))
		cout << " 충돌!!! " << endl;

	if (SphereVsOther(L"R1", L"R2"))
		cout << " 원충돌!!! " << endl;

	if (SphereVsOther(L"M1", L"R2"))
		cout << " 원충돌!!! " << endl;

	if (SphereVsBox(L"P1", L"M1"))
		cout << " 원과 박스의충돌!!! " << endl;

	CreateBullet();
}

void GameScene::Render()
{
	Scene::Render();
}

void GameScene::Exit()
{
	Scene::Exit();
}

void GameScene::CreateBullet()
{
	fCulBulletTime += D_INS->fdt;

	if (fCulBulletTime >= fCreateBulletTime)
	{
		if (DXUTIsKeyDown(VK_SPACE))
		{
			fCulBulletTime = 0;
			v_node.push_back(new Bullet());
		}
	}
}
