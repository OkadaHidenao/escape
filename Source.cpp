#include"GameState.h"

int MAIN()
{
	GameState gameState;
	gameState.Initialize();

	//ƒƒCƒ“ƒ‹[ƒv
	while (Refresh())
	{
		gameState.Update();
	}

    return 0;
}