#include "DXUT.h"
#include "Include.h"

Node::Node()
{
	position = {0,0};
	scale = { 1,1 };
	anchor = { 0.5f, 0.5f };
	color = D3DXCOLOR(255, 255, 255, 255);
	rotation = 0;
	fSpeed = 100;
	IsActive = true;
	tag = NULL;
	IsRadian = false;
}

Node::~Node()
{
}