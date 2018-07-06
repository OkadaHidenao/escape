#pragma once

#include"XLibrary11.hpp"
using namespace XLibrary;

class Map
{
private:
	//床のモデル
	Mesh floorModel;

	//壁のモデル
	Mesh wallModel;

	//アイテムのモデル
	Mesh itemModel;

	//壁のテクスチャ
	Texture mainTexture;
public:
	Map();
	~Map();

	void Initialize();
	void Draw();

	//壁の個数
	const static int wallMax = 19;
	//壁の描画設定
	Float3 wallPos[wallMax];
	Float3 wallScale[wallMax];

	//アイテムの数
	const static int itemNum = 3;
	//アイテムの描画設定
	Float3 itemPos[itemNum];
	Float3 itemScale[itemNum];
	Float3 itemAngle[itemNum];
	Texture itemTexture;

	//アイテム取得管理フラグ
	bool itemCheckFlag[itemNum];
};