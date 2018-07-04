#include"Bullet.h"

Bullet::Bullet()
{
	//コンストラクタ
}
Bullet::~Bullet()
{
	//デストラクタ
}

void Bullet::Initialize()
{
	//モデルロード
	bulletModel.CreateCube();
	//座標初期化
	bulletPos.x = bulletPos.y = bulletPos.z = 0.0f;


	//発射したらtrue
	BulletShotFlag = false;

	//弾のスケールを設定
	bulletScale.x = bulletScale.y = bulletScale.z = 0.2f;

	bulletTexture.Load(L"Graphic/bullet.png");
}

void Bullet::Draw()
{
	if (BulletShotFlag)
	{
		bulletTexture.Attach(0);
		bulletModel.position = bulletPos;
		bulletModel.scale = bulletScale;
		bulletModel.Draw();
	}
}

//弾の位置を決めます
void Bullet::BulletSet(Float3 Pos, Float3 Angle)
{

	if (BulletShotFlag)
	{
		//前に飛ばす
		bulletPos += bulletShotAngle*Bullet_Speed;
	}
	else
	{
		bulletPos = Pos;

		bulletShotAngle.x = cos(XMConvertToRadians(-Angle.y + 90.0f));
		bulletShotAngle.y = sin(XMConvertToRadians(-Angle.x));
		bulletShotAngle.z = sin(XMConvertToRadians(-Angle.y + 90.0f));
	}
}