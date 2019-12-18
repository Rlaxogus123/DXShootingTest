#pragma once
class Player : public Sprite
{
public:
	Player();
	~Player();

	float Speed;

public:
	virtual void Update();
};

