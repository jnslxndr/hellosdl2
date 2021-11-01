#include <SDL2/SDL.h>

#define FPS 60

void setup(SDL_Renderer * renderer, SDL_Window * window) {

}

void draw(SDL_Renderer * renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderDrawLineF(renderer, 0, 0, 640, 480);
}

int main (int argc, char** argv)
{
  SDL_Window* window = NULL;
  window = SDL_CreateWindow("Hello SDL2", SDL_WINDOWPOS_UNDEFINED,
           SDL_WINDOWPOS_UNDEFINED,640,480,SDL_WINDOW_SHOWN);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255 );
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  int quit = 0;
	SDL_Event e;
  setup(renderer, window);

  Uint32 frame_step = 1000 / FPS;
  Uint32 next_frame = SDL_GetTicks();

  // Main Loop starts here
	while (!quit) {
    Uint32 now = SDL_GetTicks();
    if (next_frame <= now) {
      while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) quit = 1;
      }
      draw(renderer);
      SDL_RenderPresent(renderer);
      Uint32 frame_time = fmin(SDL_GetTicks() - now, frame_step);
      next_frame += frame_step - frame_time;
      // fprintf(stderr, "frame time %i of \n", frame_time, time_step_ms);
    } else {
      SDL_Delay(1);
    }


  }
  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}
