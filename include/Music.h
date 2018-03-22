#include <iostream>
#include <SDL_mixer.h>
#ifdef MUSIC_CLASS
#else
#define STOPCONST 1000

class Music{
	public:
		Music(){
			music=nullptr;
		}
		Music(char* file){
			music=nullptr;
			Open(file);
		}
		~Music (){
			Stop(STOPCONST);
		}
		void Stop (int msToStop);
		void Play (int times);
		void Open (char* file);
		bool IsOpen ();

	private:
		Mix_Music * music;
};
#define MUSIC_CLASS
#endif

