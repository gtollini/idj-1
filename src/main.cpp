#include "../include/Game.h"
#include "../include/State.h"
#include "../include/Sprite.h"
#include "../include/Music.h"



int main (int argc, char** argv){
	Game::GetInstance().Run();
	return 0;
}
