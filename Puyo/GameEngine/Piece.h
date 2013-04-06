//
//  Piece.h
//  Puyo
//
//  Created by Filipe Teixeira on 4/3/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#ifndef __Puyo__Piece__
#define __Puyo__Piece__

#include <iostream>
#include "Puyo.h"
class Piece
{
    Puyo * puyo;
    int position[2];
public:
    
    Piece();
    void addPuyo(Puyo * puyo);
    Puyo * getPuyo();
    void removePuyo();
    bool hasPiece();
    int * getPosition();
    void setPosition(int * position);

};
#endif /* defined(__Puyo__Piece__) */
