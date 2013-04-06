//
//  GameInterface.cpp
//  Puyo
//
//  Created by Filipe Teixeira on 4/4/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#include "GameInterface.h"


bool GameInterface::init() {
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }
    this->screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    if( this->screen == NULL )
    {
        return false;
    }
    
    font = TTF_OpenFont( "BANANASP.TTF", 20 );

    if( TTF_Init() == -1 )
    {
        return false;
    }
    
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }

    SDL_WM_SetCaption( "Puyo Puyo", NULL );
    
    
    return true;
}

void GameInterface::end()
{
    SDL_Quit();

    TTF_CloseFont( font );
    TTF_Quit();
}

SDL_Surface * GameInterface::getScreen()
{
    return screen;
}

void GameInterface::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
    
    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

SDL_Surface *GameInterface::load_image( std::string filename )
{
    SDL_Surface* loadedImage = NULL;

    SDL_Surface* optimizedImage = NULL;
    
    loadedImage = SDL_LoadBMP( filename.c_str() );
    
    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        SDL_FreeSurface( loadedImage );
    }
    
    return optimizedImage;
}
SDL_Surface *GameInterface::load_image_with_alpha( std::string filename )
{
    SDL_Surface* loadedImage = NULL;
    
    SDL_Surface* optimizedImage = NULL;
    
    loadedImage = SDL_LoadBMP( filename.c_str() );
    
    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );
        
        SDL_FreeSurface( loadedImage );
        
        if( optimizedImage != NULL )
        {
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0xFF, 0xFF, 0xFF );
            
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }
    }
    
    //Return the optimized image
    return optimizedImage;
}