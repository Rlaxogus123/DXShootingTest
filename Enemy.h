#pragma once
class Enemy : public Sprite
{
public:
	Enemy();
	Enemy(Vector2 pos, int _nPattern, int Speed, int angle);
	~Enemy();

	int nPattern;
	Vector2 static_pos;
	Vector2 static_heropos;

	float fdeadtime;
	float fhomingtime;

public:
	virtual void Update();

	void Pattern1();
	void Pattern2();
	void Pattern3();
	void Pattern4();
	void Pattern5();
	void Pattern6();
	void Pattern7();
};

