#include"Player.h"

Player::Player()
{
	//�R���X�g���N�^
	camera.SetDepthTest(true);
	camera.SetPerspective(60.0f, 0.1f, 1000.0f);
}
Player::~Player()
{
	//�f�X�g���N�^
}

void Player::Initialize()
{
	playerPos = 0.0f;
	playerAngle = 0.0f;
}

void Player::Update(Map& map)
{
	//FPS�œ������Ă܂�
	playerAngle += Float3(
		-Input::GetMousePosition().y,
		Input::GetMousePosition().x,
		0.0f
	)*0.1f;

	//�p�x���
	if (playerAngle.x < -45.0f)
	{
		playerAngle.x = -45.0f;
	}
	if (playerAngle.x > 45.0f)
	{
		playerAngle.x = 45.0f;
	}
	//=================


	Float3 Velocity;

	//�O�ɐi��
	if (Input::GetKey('W'))
	{
		Velocity.x += cos(XMConvertToRadians(-playerAngle.y + 90.0f))* Speed;
		Velocity.z += sin(XMConvertToRadians(-playerAngle.y + 90.0f))* Speed;
	}
	//���ɐi��
	if (Input::GetKey('S'))
	{
		Velocity.x -= cos(XMConvertToRadians(-playerAngle.y + 90.0f))* Speed;
		Velocity.z -= sin(XMConvertToRadians(-playerAngle.y + 90.0f))* Speed;
	}
	//���ɐi��
	if (Input::GetKey('D'))
	{
		Velocity.x += cos(XMConvertToRadians(-playerAngle.y))* Speed;
		Velocity.z += sin(XMConvertToRadians(-playerAngle.y))* Speed;
	}
	//�E�ɐi��
	if (Input::GetKey('A'))
	{
		Velocity.x -= cos(XMConvertToRadians(-playerAngle.y))* Speed;
		Velocity.z -= sin(XMConvertToRadians(-playerAngle.y))* Speed;
	}

	playerPos += Velocity;

	if (MapHit(map))
	{
		playerPos -= Velocity;
	}

	camera.angles = playerAngle;
	camera.position = playerPos;
	camera.Update(false);

	//�����ƌ��_�Ƀ}�E�X�̍��W������܂�
	Input::SetMousePosition(0.0f, 0.0f);
}

//�}�b�v�̂����蔻��
bool Player::MapHit(Map& map)
{
	for (int i = 0; i < map.wallMax; i++)
	{
		if ((playerPos.x > map.wallPos[i].x - map.wallScale[i].x / 2) &&
			(playerPos.x < map.wallPos[i].x + map.wallScale[i].x / 2) &&
			(playerPos.z > map.wallPos[i].z - map.wallScale[i].z / 2) &&
			(playerPos.z < map.wallPos[i].z + map.wallScale[i].z / 2))
		{
			return true;
		}
	}
	return false;
}

//�A�C�e���̂����蔻��
bool Player::ItemCheck(Map& map)
{
	for (int i = 0; i < map.itemNum; i++)
	{
		if (!map.itemCheckFlag[i])
		{
			continue;
		}
		if ((playerPos.x > map.itemPos[i].x - map.itemScale[i].x / 2) &&
			(playerPos.x < map.itemPos[i].x + map.itemScale[i].x / 2) &&
			(playerPos.z > map.itemPos[i].z - map.itemScale[i].z / 2) &&
			(playerPos.z < map.itemPos[i].z + map.itemScale[i].z / 2))
		{
			map.itemCheckFlag[i] = false;
			return true;
		}
	}
	return false;
}