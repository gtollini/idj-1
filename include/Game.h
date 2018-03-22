#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Sprite.h"
#include "State.h"
#include "Music.h"

#ifdef GAME_CLASS
#else

class Game {
	public:
		~Game(){
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			Mix_CloseAudio();
			Mix_Quit();
			IMG_Quit();
			SDL_Quit();
			abort();
		}
		void 			Run();
		SDL_Renderer* 	GetRenderer();
		State& 		 	GetState();
		static Game& 	GetInstance();

	private:
		static Game * instance;
		SDL_Window * window;
		SDL_Renderer * renderer;
		State * state;

		Game(char * title, int width, int height){
			instance=this;
			state = new State();
			if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)){
				printf ("erro na inicialização do SDL\n");

				abort();
			}
			if (!IMG_Init (IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)){
				printf ("erro na inicialização da imagem\n");

				SDL_Quit();
				abort();
			}
			if (!Mix_Init (MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_MOD | MIX_INIT_FLUIDSYNTH | MIX_INIT_MODPLUG)
				| Mix_OpenAudio (MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)){
				printf ("Erro na inicialização do áudio\n");

				IMG_Quit();
				SDL_Quit();
				abort();
			}

			window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,  0);
			if (window==nullptr){
				printf ("Erro na inicialização da janela\n");

				Mix_CloseAudio();
				Mix_Quit();
				IMG_Quit();
				SDL_Quit();
				abort();
			}
			renderer = SDL_CreateRenderer ( window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer==nullptr){
				printf ("Erro na inicialização do renderizador\n");

				SDL_DestroyWindow(window);
				Mix_CloseAudio();
				Mix_Quit();
				IMG_Quit();
				SDL_Quit();
				abort();
			}

		}
};
#define GAME_CLASS
#endif
