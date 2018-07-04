#pragma once

#include"XLibrary11.hpp"
using namespace XLibrary;

#include"Map.h"

class Player
{
private:
	//�J�����̃C���X�^���X�쐬
	Camera camera;
	//�ړ��X�s�[�h
	const float Speed = 0.05f;
public:
	Player();
	~Player();

	void Initialize();
	void Update(Map& map);

	Float3 playerPos;
	Float3 playerAngle;

	//�}�b�v�̂����蔻��
	bool MapHit(Map& map);
	//�A�C�e���̂����蔻��
	bool ItemCheck(Map& map);
};