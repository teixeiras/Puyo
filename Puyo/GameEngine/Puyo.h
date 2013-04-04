//
//  Puyo.h
//  Puyo
//
//  Created by Filipe Teixeira on 4/3/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#ifndef __Puyo__Puyo__
#define __Puyo__Puyo__

#include <iostream>
typedef enum {
    PUYO_TYPE_BLUE,
    PUYO_TYPE_GREEN,
    PUYO_TYPE_RED,
    PUYO_TYPE_YELLOW,
    PUYO_TYPE_PURPLE
}PUYO_TYPE;

class Puyo
{
    PUYO_TYPE type;
    int position[2];
public:
    Puyo();
    Puyo(PUYO_TYPE type);
    PUYO_TYPE getPuyoType();
    int * getPosition();
};
#endif /* defined(__Puyo__Puyo__) */
