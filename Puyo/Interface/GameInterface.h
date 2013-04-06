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
#include <SDL_mixer/SDL_mixer.h>
#include <SDL_ttf/SDL_ttf.h>

#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   600
#define SCREEN_BPP      32
#define PUYO_SIZE       40
class GameInterface
{
    SDL_Surface *screen = NULL;
    TTF_Font *font = NULL;
    
public:
    bool init();
    void end();
    SDL_Surface * getScreen();
    SDL_Surface *load_image( std::string filename );
    SDL_Surface *load_image_with_alpha( std::string filename );
    void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );


};
#endif /* defined(__Puyo__GameInterface__) */
