//
//  SoundManager.h
//  PuyoWindow
//
//  Created by Filipe Teixeira on 4/5/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#ifndef __PuyoWindow__SoundManager__
#define __PuyoWindow__SoundManager__

#include <iostream>
#include <SDL/SDL.h>
#include <SDL_mixer/SDL_mixer.h>
class SoundManager;
class SoundManager
{
    static SoundManager * soundManager;
    Mix_Music *music = NULL;

public:
    
    static SoundManager * getSoundManager(){
        if (SoundManager::soundManager == NULL) {
            SoundManager::soundManager = new SoundManager();
        }
        return soundManager;
    }
    
    void playMusic(std::string music);
    void playSound(std::string sound);
    ~SoundManager();
};
#endif /* defined(__PuyoWindow__SoundManager__) */
