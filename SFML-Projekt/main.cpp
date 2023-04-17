#include <game.h>

int main()
{
	// Program entry point
	Game game; // Creating our game object
	while (!game.GetWindow()->IsDone())
	{
		// Game Loop
		// game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock();
	}

	return 0;
}