//
//  Button.h
//  PuyoWindow
//
//  Created by Filipe Teixeira on 4/5/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#ifndef __PuyoWindow__Button__
#define __PuyoWindow__Button__

#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include "GameInterface.h"

class Button
{
    bool isSelected;
    GameInterface * gameInterface;
    std::string normal;
    std::string selected;
    float position[2];
public:
    Button(GameInterface * gameInterface, std::string normal, std::string selected, float position[2]);
    void setSelected(bool selected);
    bool getSelectState();
    SDL_Surface * button();
    ~Button();
};
#endif /* defined(__PuyoWindow__Button__) */
