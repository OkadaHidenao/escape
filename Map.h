#pragma once

#include"XLibrary11.hpp"
using namespace XLibrary;

class Map
{
private:
	//���̃��f��
	Mesh floorModel;

	//�ǂ̃��f��
	Mesh wallModel;

	//�A�C�e���̃��f��
	Mesh itemModel;

	//�ǂ̃e�N�X�`��
	Texture mainTexture;
public:
	Map();
	~Map();

	void Initialize();
	void Draw();

	//�ǂ̌�
	const static int wallMax = 19;
	//�ǂ̕`��ݒ�
	Float3 wallPos[wallMax];
	Float3 wallScale[wallMax];

	//�A�C�e���̐�
	const static int itemNum = 3;
	//�A�C�e���̕`��ݒ�
	Float3 itemPos[itemNum];
	Float3 itemScale[itemNum];
	Float3 itemAngle[itemNum];
	Texture itemTexture;

	//�A�C�e���擾�Ǘ��t���O
	bool itemCheckFlag[itemNum];
};