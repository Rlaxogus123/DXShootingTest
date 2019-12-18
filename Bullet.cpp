#include "DXUT.h"
#include "Include.h"

Bullet::Bullet()
{
	SetTexture(L"Lib.jpg", 1);
	fSpeed = 100;
	position = D_INS->PlayerPos;
	tag = L"Bullet";
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	position.y -= fSpeed * D_INS->fdt;

	if (position.y < 0)
	{
		IsActive = false;
		position = { 10000,10000 };
	}
}
