#include "DXUT.h"
#include "Include.h"

Player::Player()
{
	SetTexture(L"Lib.jpg", 0);
	
	position.x = 300;
	position.y = 300;

	rotation = 10;
}

Player::~Player()
{
}

void Player::Update()
{
	if (DXUTIsKeyDown('W'))
	{
		position.y -= 5;
	}
	if (DXUTIsKeyDown('A'))
	{
		position.x -= 5;
	}
	if (DXUTIsKeyDown('S'))
	{
		position.y += 5;
	}
	if (DXUTIsKeyDown('D'))
	{
		position.x += 5;
	}

	if (position.x < 0) position.x = 0;
	if (position.x > 1280) position.x = 1280;
	if (position.y < 0) position.y = 0;
}
