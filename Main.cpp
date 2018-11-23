#include "Game.h"
#include "time.h"

int main(){
	srand(time(NULL));
	Game game(20);
	game.board_build();
	for (int i = 0; i < 1000; i++)
	{
		game.status();
		game.paint();
	}
	return 0;
}