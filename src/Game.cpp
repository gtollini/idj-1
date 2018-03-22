#include <SDL_image.h>
#include <SDL_mixer.h>
#include "../include/Game.h"
#include "../include/State.h"

Game *Game::instance;

Game& Game::GetInstance () {
	char nome[40] = "Gabriel de Carvalho Tollini, 140020454";
	if (instance  ==  nullptr) instance = new Game(nome, 1024, 600);
	return *instance;
	}

State& Game::GetState(){
	return *state;
}

SDL_Renderer* Game::GetRenderer(){
	return renderer;
}

void Game::Run(){
	state->LoadAssets();
	while (!state->QuitRequested()){
		state->Update(0);
		state->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(33);
	}
}
