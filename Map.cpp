#include"Map.h"

Map::Map()
{
	//コンストラクタ
}
Map::~Map()
{
	//デストラクタ
}

void Map::Initialize()
{
	mainTexture.Load(L"Graphic/main.png");
	itemTexture.Load(L"Graphic/Bricks.png");

	//床描画設定
	floorModel.CreatePlane(Float2(20.0f, 20.0f));
	floorModel.position.x = 0.0f;
	floorModel.position.y = -1.0f;
	floorModel.position.z = 0.0f;
	floorModel.angles.x = 90.0f;

	//壁描画設定=============================
	wallModel.CreateCube();

	//-x側の壁
	wallPos[0].x = -18.0f;
	wallPos[0].y = 1.5f;
	wallPos[0].z = 0.0f;
	wallScale[0].x = 1.0f;
	wallScale[0].y = 5.0f;
	wallScale[0].z = 40.0f;

	//+x側の壁
	wallPos[1].x = 18.0f;
	wallPos[1].y = 1.5f;
	wallPos[1].z = 0.0f;
	wallScale[1].x = 1.0f;
	wallScale[1].y = 5.0f;
	wallScale[1].z = 40.0f;

	//+z側の壁
	wallPos[2].x = 0.0f;
	wallPos[2].y = 1.5f;
	wallPos[2].z = 18.0f;
	wallScale[2].x = 40.0f;
	wallScale[2].y = 5.0f;
	wallScale[2].z = 1.0f;

	//-z側の壁
	wallPos[3].x = 0.0f;
	wallPos[3].y = 1.5f;
	wallPos[3].z = -18.0f;
	wallScale[3].x = 40.0f;
	wallScale[3].y = 5.0f;
	wallScale[3].z = 1.0f;

	//ここからマップの中の描画に入ります
	wallPos[4].x = -3.0f;
	wallPos[4].y = 0.0f;
	wallPos[4].z = 2.0f;
	wallScale[4].x = 1.0f;
	wallScale[4].y = 5.0f;
	wallScale[4].z = 17.0f;

	wallPos[5].x = 3.0f;
	wallPos[5].y = 0.0f;
	wallPos[5].z = 5.0f;
	wallScale[5].x = 3.0f;
	wallScale[5].y = 5.0f;
	wallScale[5].z = 1.0f;

	wallPos[6].x = 3.0f;
	wallPos[6].y = 0.0f;
	wallPos[6].z = 0.0f;
	wallScale[6].x = 3.0f;
	wallScale[6].y = 5.0f;
	wallScale[6].z = 1.0f;

	wallPos[7].x = 5.0f;
	wallPos[7].y = 0.0f;
	wallPos[7].z = 7.0f;
	wallScale[7].x = 1.0f;
	wallScale[7].y = 5.0f;
	wallScale[7].z = 15.0f;

	wallPos[8].x = 3.0f;
	wallPos[8].y = 0.0f;
	wallPos[8].z = 12.0f;
	wallScale[8].x = 5.0f;
	wallScale[8].y = 5.0f;
	wallScale[8].z = 5.0f;

	wallPos[9].x = 15.0f;
	wallPos[9].y = 0.0f;
	wallPos[9].z = 10.0f;
	wallScale[9].x = 12.0f;
	wallScale[9].y = 5.0f;
	wallScale[9].z = 6.0f;

	wallPos[10].x = 15.0f;
	wallPos[10].y = 0.0f;
	wallPos[10].z = 3.0f;
	wallScale[10].x = 20.0f;
	wallScale[10].y = 5.0f;
	wallScale[10].z = 3.0f;

	wallPos[11].x = 8.0f;
	wallPos[11].y = 0.0f;
	wallPos[11].z = -5.0f;
	wallScale[11].x = 1.0f;
	wallScale[11].y = 5.0f;
	wallScale[11].z = 15.0f;

	wallPos[12].x = 3.0f;
	wallPos[12].y = 0.0f;
	wallPos[12].z = -8.5f;
	wallScale[12].x = 5.0f;
	wallScale[12].y = 5.0f;
	wallScale[12].z = 8.0f;

	wallPos[13].x = -10.0f;
	wallPos[13].y = 0.0f;
	wallPos[13].z = -8.5f;
	wallScale[13].x = 6.5f;
	wallScale[13].y = 5.0f;
	wallScale[13].z = 5.0f;

	wallPos[14].x = -10.0f;
	wallPos[14].y = 0.0f;
	wallPos[14].z = 0.0f;
	wallScale[14].x = 6.5f;
	wallScale[14].y = 5.0f;
	wallScale[14].z = 5.0f;

	wallPos[15].x = -10.0f;
	wallPos[15].y = 0.0f;
	wallPos[15].z = 5.0f;
	wallScale[15].x = 15.0f;
	wallScale[15].y = 5.0f;
	wallScale[15].z = 1.0f;

	wallPos[16].x = -10.0f;
	wallPos[16].y = 0.0f;
	wallPos[16].z = 13.0f;
	wallScale[16].x = 5.0f;
	wallScale[16].y = 5.0f;
	wallScale[16].z = 9.0f;

	wallPos[17].x = -3.0f;
	wallPos[17].y = 0.0f;
	wallPos[17].z = -10.0f;
	wallScale[17].x = 2.0f;
	wallScale[17].y = 5.0f;
	wallScale[17].z = 3.0f;

	wallPos[18].x = 15.0f;
	wallPos[18].y = 0.0f;
	wallPos[18].z = -7.0f;
	wallScale[18].x = 7.0f;
	wallScale[18].y = 5.0f;
	wallScale[18].z = 5.0f;
	//=======================================

	//アイテム
	itemPos[0].x = -15.0f;
	itemPos[0].y = 0.0f;
	itemPos[0].z = 15.0f;
	itemScale[0].x = 1.0f;
	itemScale[0].y = 1.0f;
	itemScale[0].z = 1.0f;
	itemAngle[0].x = 0.0f;
	itemAngle[0].y = 0.0f;
	itemAngle[0].z = 0.0f;

	itemPos[1].x = 15.0f;
	itemPos[1].y = 0.0f;
	itemPos[1].z = 5.5f;
	itemScale[1].x = 1.0f;
	itemScale[1].y = 1.0f;
	itemScale[1].z = 1.0f;
	itemAngle[1].x = 0.0f;
	itemAngle[1].y = 0.0f;
	itemAngle[1].z = 0.0f;

	itemPos[2].x = 15.0f;
	itemPos[2].y = 0.0f;
	itemPos[2].z = -2.0f;
	itemScale[2].x = 1.0f;
	itemScale[2].y = 1.0f;
	itemScale[2].z = 1.0f;
	itemAngle[2].x = 0.0f;
	itemAngle[2].y = 0.0f;
	itemAngle[2].z = 0.0f;

	//=======================================
	for (int i = 0; i < itemNum; i++)
	{
		itemCheckFlag[i] = true;
	}
}

void Map::Draw()
{
	mainTexture.Attach(0);
	//床描画
	floorModel.angles;
	floorModel.Draw();

	//壁描画
	for (int i = 0; i < wallMax; i++)
	{
		wallModel.position = wallPos[i];
		wallModel.scale = wallScale[i];
		wallModel.Draw();
	}

	//アイテム描画
	for (int i = 0; i < itemNum; i++)
	{
		if (itemCheckFlag[i])
		{
			itemTexture.Attach(0);
			itemModel.position = itemPos[i];
			itemModel.scale = itemScale[i];
			itemModel.angles = itemAngle[i];
			itemModel.Draw();
		}
		itemAngle[i].y += 3.0f;
	}
}