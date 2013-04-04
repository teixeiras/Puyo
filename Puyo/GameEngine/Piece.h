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
    
public:
    
    Piece();
    void addPuyo(Puyo * puyo);
    Puyo * getPuyo();
    void removePuyo();
    bool hasPiece();
    
    
};
#endif /* defined(__Puyo__Piece__) */
