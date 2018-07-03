#pragma once

#include"XLibrary11.hpp"
using namespace XLibrary;

#define Bullet_Speed 0.1f

class Bullet
{
private:
	//�e�̃��f��
	Mesh bulletModel;
	//�e�̍��W
	Float3 bulletPos;
	//�e�����˂����p�x
	Float3 bulletShotAngle;
	//�o���b�g�̑傫��
	Float3 bulletScale;

	Texture bulletTexture;

public:
	Bullet()
	{
		//�R���X�g���N�^
	}
	~Bullet()
	{
		//�f�X�g���N�^
	}

	void Initialize()
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

	void Draw()
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
	void BulletSet(Float3 Pos, Float3 Angle)
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
	//�e�𔭎˂��Ă��邩�̃t���O
	bool BulletShotFlag;
};