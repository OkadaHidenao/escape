#include"GameState.h"

int MAIN()
{
	GameState gameState;
	gameState.Initialize();

	//メインループ
	while (Refresh())
	{
		gameState.Update();
	}

    return 0;
}