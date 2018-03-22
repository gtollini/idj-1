#include <SDL.h>
#ifdef SPRITE_CLASS
#else
class Sprite {
	public:
		Sprite(){
			texture=nullptr;
		}
		Sprite(char * file){
			texture=nullptr;
			Open (file);
		}
		~Sprite(){
			SDL_DestroyTexture(texture);
		}
		void Open (char * file);
		void SetClip (int x, int y, int w, int h);
		void Render (int x, int y);
		int GetWidth ();
		int GetHeight();
		bool IsOpen();
	private:
		SDL_Texture * texture;
		int width;
		int height;
		SDL_Rect * clipRect;
};
#define SPRITE_CLASS
#endif
