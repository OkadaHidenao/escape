#include"GameState.h"

int MAIN()
{
	GameState gameState;
	gameState.Initialize();

	//���C�����[�v
	while (Refresh())
	{
		gameState.Update();
	}

    return 0;
}