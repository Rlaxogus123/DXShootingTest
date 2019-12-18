#pragma once
class Sprite : public Node
{
public:
	Sprite();
	~Sprite();

public:
	LPD3DXSPRITE sprite;
	LPDIRECT3DTEXTURE9 texture;

public:
	virtual void Render();
	virtual void Update();
	void SetTexture(WCHAR* path, int Layer);
};

