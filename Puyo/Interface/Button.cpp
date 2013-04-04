//
//  Button.cpp
//  PuyoWindow
//
//  Created by Filipe Teixeira on 4/5/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#include "Button.h"

Button::Button(GameInterface * gameInterface, std::string normal, std::string selected, float  position[])
{
    this->gameInterface = gameInterface;
    this->normal = normal;
    this->selected = selected;

    this->position[0] = position[0];
    this->position[1] = position[1];
}

Button::~Button()
{
    
    
}

void Button::setSelected(bool selected)
{
    isSelected = selected;
}

bool Button::getSelectState()
{
    return isSelected;
}

SDL_Surface * Button::button()
{
    
    SDL_Surface * button = this->gameInterface->load_image(isSelected?selected:normal);
    this->gameInterface->apply_surface( position[0], position[1], button, this->gameInterface->getScreen() );
   return button;
}