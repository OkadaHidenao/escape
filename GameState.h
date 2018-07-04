#pragma once

#include"XLibrary11.hpp"
using namespace XLibrary;

#include"Map.h"
#include"Player.h"
#include"Bullet.h"

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

	//�Q�[������p
	Sequence gameSeq = GAME_TITLE;

	//�C���X�^���X�쐬�Q
	Player player;
	Bullet bullet;
	Map *map;
	Camera camera;
	//===================

	//�A�C�e���Ǘ��t���O
	int itemCheckNumFlag;

	//���ԕ`��p
	Text timeText;
	float time;
	//==========

public:
	GameState();
	~GameState();

	void Initialize();
	void SetUpGame();
	void Update();

	void GameTitle();
	void GameTutorial();
	void GameMain();
	void GameClear();
	void GameOver();
};
