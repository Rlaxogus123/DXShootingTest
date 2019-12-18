#include "DXUT.h"
#include "Include.h"

Enemy::Enemy()
{
	SetTexture(L"Lib.png", 0);
	tag = L"B1";

	fdeadtime = 0;
	fhomingtime = 0;
}

Enemy::Enemy(Vector2 pos, int _nPattern, int Speed, int angle)
{
	SetTexture(L"Lib.jpg", 0);
	tag = L"B1";
	fSpeed = Speed;
	position = pos;
	rotation = angle;
	nPattern = _nPattern;

	static_pos = pos;
	static_heropos = D_INS->PlayerPos;

	fdeadtime = 0;
	fhomingtime = 0;
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	switch (nPattern)
	{
	case 1:
		Pattern1();
		break;
	case 2:
		Pattern2();
		break;
	case 3:
		Pattern3();
		break;
	case 4:
		Pattern4();
		break;
	case 5:
		Pattern5();
		break;
	case 6:
		Pattern6();
		break;
	case 7:
		Pattern7();
		break;
	}

	if (position.x < 0) IsActive = false;
	if (position.x > 1280) IsActive = false;
	if (position.y < 0) IsActive = false;
	if (position.y > 720) IsActive = false;

	if(fdeadtime >= 1) IsActive = false;
}

void Enemy::Pattern1()
{
	// 보고있는 각도쪽으로 이동
	Vector2 Dir;
	Dir.x = cos(D3DXToRadian(rotation)) * fSpeed * D_INS->fdt;
	Dir.y = sin(D3DXToRadian(rotation)) * fSpeed * D_INS->fdt;
	position += Dir;
}

void Enemy::Pattern2()
{
	double xdf = static_pos.x - static_heropos.x;
	double ydf = static_pos.y - static_heropos.y;
	double ang = D3DXToDegree(atan2(ydf, xdf)) - 180;
	rotation = ang;

	Pattern1();
}

void Enemy::Pattern3()
{
	position.y = static_pos.y + (int)(sin(position.x * D3DX_PI / 180) * 100);
	Pattern1();
}

void Enemy::Pattern4()
{
	position.y = static_pos.y + (int)(sin(position.x * D3DX_PI / 180) * -100);
	Pattern1();
}

void Enemy::Pattern5()
{
	position.x = static_pos.x + (int)(sin(D3DX_PI * position.y / 180) * 100);
	Pattern1();
}

void Enemy::Pattern6()
{
	position.x = static_pos.x +(int)(sin(D3DX_PI * position.y / 180) * -100);
	Pattern1();
}

void Enemy::Pattern7()
{
	if (fhomingtime <= 1)
	{
		double xdf = position.x - D_INS->PlayerPos.x;
		double ydf = position.y - D_INS->PlayerPos.y;
		double ang = D3DXToDegree(atan2(ydf, xdf)) - 180;
		rotation = ang;
		fhomingtime += D_INS->fdt / 3;
	}

	Pattern1();
}
