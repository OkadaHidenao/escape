#include"XLibrary11.hpp"
using namespace XLibrary;

#include"GameState.hpp"

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