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
	Bullet();
	~Bullet();

	void Initialize();
	void Draw();
	//�e�̈ʒu�����߂܂�
	void BulletSet(Float3 Pos, Float3 Angle);

	//�e�𔭎˂��Ă��邩�̃t���O
	bool BulletShotFlag;
};