#pragma once
class Node
{
public:
	Node();
	virtual ~Node();

public:
	Vector2 position;
	Vector2 scale;
	Vector2 anchor;
	float	rotation;
	float	fSpeed;

	D3DXIMAGE_INFO	info;
	D3DXMATRIX		matrix;
	D3DCOLOR		color;

	WCHAR* tag;

	RECT ImgRect;
	RECT ColRect;

	int nLayer;
	bool IsActive;
	bool IsRadian;

public:
	virtual void Update() = 0;
	virtual void Render() = 0;
};

