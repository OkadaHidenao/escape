#pragma once

#include"XLibrary11.hpp"
using namespace XLibrary;

#include"Map.h"

class Player
{
private:
	//カメラのインスタンス作成
	Camera camera;
	//移動スピード
	const float Speed = 0.05f;
public:
	Player();
	~Player();

	void Initialize();
	void Update(Map& map);

	Float3 playerPos;
	Float3 playerAngle;

	//マップのあたり判定
	bool MapHit(Map& map);
	//アイテムのあたり判定
	bool ItemCheck(Map& map);
};