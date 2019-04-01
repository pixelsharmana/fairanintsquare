#include <SDL/SDL.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main ( int argc, char *argv[] ) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_WM_SetCaption("Fair ain't square", "Fair ain't square");
    SDL_Surface* screen = SDL_SetVideoMode(640, 480, 0, 0);
}
