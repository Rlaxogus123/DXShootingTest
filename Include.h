#pragma once
typedef D3DXVECTOR2 Vector2;
typedef D3DXVECTOR3 Vector3;
typedef D3DXCOLOR Color;

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "Node.h"
#include "Sprite.h"

#include "Scene.h"

#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "Enemy.h"

#include "GameScene.h"
#include "MenuScene.h"

#include "Instance.h"

#define D_INS Instance::Ins()