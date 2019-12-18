#include "DXUT.h"
#include "Include.h"

Monster::Monster()
{
	position.x = 300;
	position.y = 300;
}

Monster::~Monster()
{
}

void Monster::Update()
{
	if (DXUTIsKeyDown(VK_UP))
	{
		position.y -= 5;
	}
	if (DXUTIsKeyDown(VK_LEFT))
	{
		position.x -= 5;
	}
	if (DXUTIsKeyDown(VK_DOWN))
	{
		position.y += 5;
	}
	if (DXUTIsKeyDown(VK_RIGHT))
	{
		position.x += 5;
	}

	if (position.x < 0) position.x = 0;
	if (position.x > 1280) position.x = 1280;
	if (position.y < 0) position.y = 0;
	if (position.y > 720) position.y = 720;
}
