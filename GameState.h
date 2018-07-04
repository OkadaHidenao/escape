#pragma once

#include"XLibrary11.hpp"
using namespace XLibrary;

#include"Map.h"
#include"Player.h"
#include"Bullet.h"

//enumでゲームを分岐
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
	//タイトル,クリア,オーバー画面を描画するための設定
	Sprite titleSprite;
	Sprite clearSprite;
	Sprite overSprite;

	//説明文描画設定
	Sprite messageSprite[3];

	//ゲーム分岐用
	Sequence gameSeq = GAME_TITLE;

	//インスタンス作成群
	Player player;
	Bullet bullet;
	Map *map;
	Camera camera;
	//===================

	//アイテム管理フラグ
	int itemCheckNumFlag;

	//時間描画用
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
