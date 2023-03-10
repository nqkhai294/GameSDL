#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        std::cout << "SDL Init. Error: " << SDL_GetError() << std::endl;

    SDL_Window* window = nullptr;
    window = SDL_CreateWindow("Game SDL ", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
        std::cout << "Create Window. Error: " << SDL_GetError() << std::endl;

    SDL_Renderer* renderer = nullptr;
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr)
        std::cout << "Create Renderer. Error: " << SDL_GetError() << std::endl;

    SDL_Rect dst;
    dst.x = 100;
    dst.y = 100;
    dst.w = 50;
    dst.h = 100;
    int step = 20;

    SDL_Texture* background = nullptr;
    background = IMG_LoadTexture(renderer, "bg2.png");
    if (background == nullptr)
        std::cout << "Load Background. Error: " << SDL_GetError() << std::endl;

    SDL_Texture* character = nullptr;
    character = IMG_LoadTexture(renderer, "char.jpg");
    if (character == nullptr)
        std::cout << "Load Character. Error: " << SDL_GetError() << std::endl;


    bool isRunning = true;
    SDL_Event e;
    while (isRunning)
    {
         SDL_RenderCopy(renderer, background, NULL, NULL);
        SDL_RenderCopy(renderer, character, NULL, &dst);
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT) isRunning = false;

            if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_UP:
                    dst.y -= step;
                    break;
                case SDLK_DOWN:
                    dst.y += step;
                    break;
                case SDLK_RIGHT:
                    dst.x += step;
                    break;
                case SDLK_LEFT:
                    dst.x -= step;
                    break;

                default:
                    break;
                }
            }
            else if (e.type == SDL_KEYUP)
            {
                switch(e.key.keysym.sym)
                {
                    {
                case SDLK_UP:
                    dst.y += step;
                    break;
                case SDLK_DOWN:
                    dst.y -= step;
                    break;
                case SDLK_RIGHT:
                    dst.x -= step;
                    break;
                case SDLK_LEFT:
                    dst.x += step;
                    break;
                default:
                    break;
                }
                }
            }
        }



        SDL_RenderClear(renderer);

    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
