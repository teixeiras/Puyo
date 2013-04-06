//
//  SoundManager.cpp
//  PuyoWindow
//
//  Created by Filipe Teixeira on 4/5/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#include "SoundManager.h"

#define NUM_SOUNDS 2
struct sample {
    Uint8 *data;
    Uint32 dpos;
    Uint32 dlen;
} sounds[NUM_SOUNDS];



//Load the sound effects


SoundManager * SoundManager::soundManager=NULL;

void SoundManager::playMusic(std::string music)
{
    this->music = Mix_LoadMUS( music.c_str() );
    if( this->music == NULL )
    {
        return ;
    }

    if( Mix_PlayingMusic() == 0 )
    {
        if( Mix_PlayMusic( this->music, -1 ) == -1 )
        {
            return ;
        }
    }
    
}
void SoundManager::playSound(std::string sound)
{
    Mix_Chunk * soundChunk = Mix_LoadWAV( "scratch.wav" );
    //Play the scratch effect
    if( Mix_PlayChannel( -1, soundChunk, 0 ) == -1 )
    {
        return ;
    }
    Mix_FreeChunk(soundChunk);

}
SoundManager::~SoundManager()
{
    Mix_FreeMusic( music );
    
    
    //Quit SDL_mixer
    Mix_CloseAudio();
    
   
   
}
