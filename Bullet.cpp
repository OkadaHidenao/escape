#include"Bullet.h"

Bullet::Bullet()
{
	//�R���X�g���N�^
}
Bullet::~Bullet()
{
	//�f�X�g���N�^
}

void Bullet::Initialize()
{
	//���f�����[�h
	bulletModel.CreateCube();
	//���W������
	bulletPos.x = bulletPos.y = bulletPos.z = 0.0f;


	//���˂�����true
	BulletShotFlag = false;

	//�e�̃X�P�[����ݒ�
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

//�e�̈ʒu�����߂܂�
void Bullet::BulletSet(Float3 Pos, Float3 Angle)
{

	if (BulletShotFlag)
	{
		//�O�ɔ�΂�
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