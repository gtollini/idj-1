#include <SDL.h>
#include "Sprite.h"
#include "Music.h"
#ifdef STATE_CLASS
#else


class State{
	public:
		State(){
			quitRequested = false;
			//bg = new Sprite((char *)"img/title.jpg");
			music = new Music((char *)"audio/stageState.ogg");
			printf ("Inicializando Música... %s\n", music->IsOpen()?"true":"false");
			music->Play(1);

		}
		bool QuitRequested();
		void LoadAssets();
		void Update(float dt);
		void Render();
	private:
		Sprite *bg;
		Music *music;
		bool quitRequested;
};

#define STATE_CLASS
#endif
