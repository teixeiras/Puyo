//
//  GameInterface.h
//  Puyo
//
//  Created by Filipe Teixeira on 4/4/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#ifndef __Puyo__GameInterface__
#define __Puyo__GameInterface__

#include <iostream>
#include <SDL/SDL.h>
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int SCREEN_BPP;
class GameInterface
{
    SDL_Surface *screen = NULL;

public:
    bool init();
    void end();
    SDL_Surface * getScreen();
    SDL_Surface *load_image( std::string filename );
    void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
};
#endif /* defined(__Puyo__GameInterface__) */
