#pragma once

#include"XLibrary11.hpp"
using namespace XLibrary;

#include"Map.hpp"
#include"Player.hpp"
#include"Bullet.hpp"

//enum�ŃQ�[���𕪊�
enum Sequence
{
	GAME_TITLE,
	GAME_TUTORIAL,
	GAME_MAIN,
	GAME_CLEAR,
	GAME_OVER
};

class GameState
{
private:
	//�^�C�g��,�N���A,�I�[�o�[��ʂ�`�悷�邽�߂̐ݒ�
	Sprite titleSprite;
	Sprite clearSprite;
	Sprite overSprite;

	//�������`��ݒ�
	Sprite messageSprite[3];

	//Sprite mainSprite;

	//�Q�[������p
	Sequence gameSeq = GAME_TITLE;

	//�C���X�^���X�쐬�Q
	Player player;
	Bullet bullet;
	Map *map;
	Camera camera;

	int itemCheckNumFlag;
	Text timeText;
	float time;

public:
	GameState()
	{
		//�R���X�g���N�^
		map = new Map;
	}
	~GameState()
	{
		//�f�X�g���N�^
		delete map;
	}
	void Initialize()
	{
		//���C�����[�v�O�ɌĂ�
		//�Q�[���̏�������ǂݍ���

		//�^�C�g��,�Q�[���I�[�o�[,�Q�[���N���A��ʂ̃X�v���C�g���[�h
		titleSprite.Load(L"Graphic/Title.png");
		clearSprite.Load(L"Graphic/Clear.png");
		overSprite.Load(L"Graphic/over.png");

		//�������X�v���C�g���[�h
		messageSprite[0].Load(L"Graphic/messageOne.png");
		messageSprite[1].Load(L"Graphic/messageTwo.png");
		messageSprite[2].Load(L"Graphic/messagaThree.png");

		bullet.Initialize();
		map->Initialize();

		itemCheckNumFlag = 0;
		time = 61;
	}

	void SetUpGame()
	{
		//�Q�[���̐ݒ��������
		//���g���C����Ƃ��ȂǂɌĂт܂�
		player.Initialize();
		bullet.Initialize();
		itemCheckNumFlag = 0;
		time = 61;
		for (int i = 0; i < map->itemNum; i++)
		{
			map->itemCheckFlag[i] = true;
		}
	}

	void Update()
	{
		camera.Update();


		//���ۂ̓���
		switch (gameSeq)
		{
		case GAME_TITLE:
			GameTitle();
			break;

		case GAME_TUTORIAL:
			GameTutorial();
			break;

		case GAME_MAIN:
			GameMain();
			break;

		case GAME_CLEAR:
			GameClear();
			break;

		case GAME_OVER:
			GameOver();
			break;

		default:
			break;
		}
	}

	void GameTitle()
	{
		//�^�C�g��
		titleSprite.Draw();
		if (Input::GetKeyDown(VK_LBUTTON))
		{
			gameSeq = GAME_TUTORIAL;
		}
		Input::SetMousePosition(0.0f, 0.0f);
	}

	void GameTutorial()
	{
		//�`���[�g���A��
		static int i = 0;
		messageSprite[i].Draw();
		if (Input::GetKeyDown(VK_LBUTTON))
		{
			i++;
			if (i > 2)
			{
				i = 0;
				SetUpGame();
				gameSeq = GAME_MAIN;
			}
		}
		Input::SetMousePosition(0.0f, 0.0f);
	}

	void GameMain()
	{
		//���C��
		player.Update(*map);
		bullet.Draw();
		map->Draw();

		//�A�C�e���̊l������
		if (player.ItemCheck(*map))
		{
			itemCheckNumFlag++;
		}
		//�A�C�e����3�Ƃ�΃N���A��ʂɈڍs
		if (itemCheckNumFlag == 3)
		{
			gameSeq = GAME_CLEAR;
		}


		//�e�̔��ˈʒu��ݒ�
		bullet.BulletSet(player.playerPos, player.playerAngle);

		//�}�E�X�̍��{�^������������
		if (Input::GetKeyDown(VK_LBUTTON))
		{
			//�e����
			if (!bullet.BulletShotFlag)
			{
				bullet.BulletShotFlag = true;
			}
		}
		camera.Update(false);

		time -= Timer::GetDeltaTime();

		timeText.Create(std::to_wstring((int)time), 16.0f);
		timeText.scale = 5.0f;
		timeText.position = Float3(0.0f, 200.0f, 0.0f);
		timeText.Draw();

		if (time < 1)
		{
			gameSeq = GAME_OVER;
		}
	}

	void GameClear()
	{
		//�N���A

		clearSprite.Draw();
		if (Input::GetKeyDown(VK_LBUTTON))
		{
			gameSeq = GAME_TITLE;
		}
		Input::SetMousePosition(0.0f, 0.0f);
	}

	void GameOver()
	{
		//�I�[�o�[

		overSprite.Draw();
		//���N���b�N���g���C
		if (Input::GetKeyDown(VK_LBUTTON))
		{
			SetUpGame();
			gameSeq = GAME_MAIN;
		}
		//�E�N���b�N�^�C�g��
		if (Input::GetKeyDown(VK_RBUTTON))
		{
			gameSeq = GAME_TITLE;
		}
		Input::SetMousePosition(0.0f, 0.0f);
	}
};
