//
//  Puyo.cpp
//  Puyo
//
//  Created by Filipe Teixeira on 4/3/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#include "Puyo.h"
#include <time.h>

Puyo::Puyo()
{
    srand ((int)time(NULL));
    this->type = static_cast<PUYO_TYPE>(rand() % 5);
}

Puyo::Puyo(PUYO_TYPE  type)
{
    this->type = type;
}

PUYO_TYPE Puyo::getPuyoType()
{
    return this->type;
}

int * Puyo::getPosition()
{
    return this->position;
}