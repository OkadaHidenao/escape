#include"XLibrary11.hpp"
using namespace XLibrary;

#include"GameState.hpp"

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