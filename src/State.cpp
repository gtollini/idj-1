#include "../include/State.h"
#include "../include/Sprite.h"
#include "../include/Music.h"


void State::LoadAssets(){
	music->Play(-1);
}

void State::Update(float dt){
	quitRequested = SDL_QuitRequested();
}

void State::Render(){
}

bool State::QuitRequested(){
	return quitRequested;
}

