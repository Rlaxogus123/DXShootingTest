#include "DXUT.h"
#include "Include.h"

Sprite::Sprite()
{
	texture = nullptr;
	sprite = nullptr;
}

Sprite::~Sprite()
{
}

void Sprite::Render()
{
	D3DXMatrixTransformation2D(&matrix, &anchor, 0, &scale, &anchor, rotation, &position);

	sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);

	Vector3 center(info.Width, info.Height, 0);
	center.x *= anchor.x;
	center.y *= anchor.y;

	sprite->Draw(texture, &ImgRect, &center, &(Vector3)position, color);

	SetRect(&ColRect, position.x - (info.Width * scale.x / 2), position.y - (info.Height * scale.y / 2),
		position.x + (info.Width * scale.x / 2), position.y + (info.Height * scale.y / 2));

	sprite->End();

	if (IsRadian) D_INS->DrawCircle(position, 100, D3DCOLOR_XRGB(255, 0, 0));
	else D_INS->DrawBox(ColRect, D3DCOLOR_XRGB(255, 0, 0));
}

void Sprite::Update()
{
}

void Sprite::SetTexture(WCHAR* path, int Layer)
{
	D3DXCreateSprite(DXUTGetD3D9Device(), &sprite);

	D3DXCreateTextureFromFileEx(DXUTGetD3D9Device(), path, -2, -2, 1, 0,
		D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_FILTER_NONE, 0, &info, nullptr, &texture);

	SetRect(&ImgRect, 0, 0, info.Width, info.Height);

	nLayer = Layer;
}
