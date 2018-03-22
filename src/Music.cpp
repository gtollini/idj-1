#include "../include/Music.h"
#include <SDL_mixer.h>


void Music::Play(int i){
	Mix_PlayMusic (music, i);
}

void Music::Stop(int msToStop){
	Mix_FadeOutMusic (msToStop);
}

void Music::Open(char *file){
	music = Mix_LoadMUS (file);
	if (music == nullptr) printf ("Erro ao carregar música\n");
}

bool Music::IsOpen(){
	return music!=nullptr;
}
