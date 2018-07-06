#include"GameState.h"

GameState::GameState()
{
	//コンストラクタ
	map = new Map;
}
GameState::~GameState()
{
	//デストラクタ
	delete map;
}

void GameState::Initialize()
{
	//メインループ前に呼ぶ
	//ゲームの初期情報を読み込み

	//タイトル,ゲームオーバー,ゲームクリア画面のスプライトロード
	titleSprite.Load(L"Graphic/Title.png");
	clearSprite.Load(L"Graphic/Clear.png");
	overSprite.Load(L"Graphic/over.png");

	//説明文スプライトロード
	messageSprite[0].Load(L"Graphic/messageOne.png");
	messageSprite[1].Load(L"Graphic/messageTwo.png");
	messageSprite[2].Load(L"Graphic/messagaThree.png");

	bullet.Initialize();
	map->Initialize();

	itemCheckNumFlag = 0;
	time = 61;
}

void GameState::SetUpGame()
{
	//ゲームの設定を初期化
	//リトライするときなどに呼びます
	player.Initialize();
	bullet.Initialize();
	itemCheckNumFlag = 0;
	time = 61;
	for (int i = 0; i < map->itemNum; i++)
	{
		map->itemCheckFlag[i] = true;
	}
}

void GameState::Update()
{
	camera.Update();

	//実際の動き
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

void GameState::GameTitle()
{
	//タイトル
	titleSprite.Draw();
	if (Input::GetKeyDown(VK_LBUTTON))
	{
		gameSeq = GAME_TUTORIAL;
	}
	Input::SetMousePosition(0.0f, 0.0f);
}

void GameState::GameTutorial()
{
	//チュートリアル
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

void GameState::GameMain()
{
	//メイン
	player.Update(*map);
	bullet.Draw();
	map->Draw();

	//アイテムの獲得処理
	if (player.ItemCheck(*map))
	{
		itemCheckNumFlag++;
	}
	//アイテムを3個とればクリア画面に移行
	if (itemCheckNumFlag == 3)
	{
		gameSeq = GAME_CLEAR;
	}


	//弾の発射位置を設定
	bullet.BulletSet(player.playerPos, player.playerAngle);

	//マウスの左ボタンを押したら
	if (Input::GetKeyDown(VK_LBUTTON))
	{
		//弾発射
		if (!bullet.BulletShotFlag)
		{
			int a = 0;
			//bullet.BulletShotFlag = true;
		}
	}
	camera.Update(false);

	//時間系=============================================
	time -= Timer::GetDeltaTime();

	timeText.Create(std::to_wstring((int)time), 16.0f);
	timeText.scale = 5.0f;
	timeText.position = Float3(0.0f, 200.0f, 0.0f);
	timeText.Draw();

	//制限時間でゲームオーバー
	if (time < 1)
	{
		gameSeq = GAME_OVER;
	}
}

void GameState::GameClear()
{
	//クリア

	clearSprite.Draw();
	if (Input::GetKeyDown(VK_LBUTTON))
	{
		gameSeq = GAME_TITLE;
	}
	Input::SetMousePosition(0.0f, 0.0f);
}

void GameState::GameOver()
{
	//オーバー

	overSprite.Draw();
	//左クリックリトライ
	if (Input::GetKeyDown(VK_LBUTTON))
	{
		SetUpGame();
		gameSeq = GAME_MAIN;
	}
	//右クリックタイトル
	if (Input::GetKeyDown(VK_RBUTTON))
	{
		gameSeq = GAME_TITLE;
	}
	Input::SetMousePosition(0.0f, 0.0f);
}