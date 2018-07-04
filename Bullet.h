#pragma once

#include"XLibrary11.hpp"
using namespace XLibrary;

#define Bullet_Speed 0.1f

class Bullet
{
private:
	//弾のモデル
	Mesh bulletModel;
	//弾の座標
	Float3 bulletPos;
	//弾が発射される角度
	Float3 bulletShotAngle;
	//バレットの大きさ
	Float3 bulletScale;

	Texture bulletTexture;

public:
	Bullet();
	~Bullet();

	void Initialize();
	void Draw();
	//弾の位置を決めます
	void BulletSet(Float3 Pos, Float3 Angle);

	//弾を発射しているかのフラグ
	bool BulletShotFlag;
};