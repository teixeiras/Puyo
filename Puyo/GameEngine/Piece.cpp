//
//  Piece.cpp
//  Puyo
//
//  Created by Filipe Teixeira on 4/3/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#include "Piece.h"
Piece::Piece()
{
    this->puyo = NULL;
}

void Piece::addPuyo(Puyo * puyo)
{
    this->puyo = puyo;
}

Puyo * Piece::getPuyo()
{
    return this->puyo;
}

void Piece::removePuyo()
{
    this->puyo = NULL;
}
bool Piece::hasPiece()
{
    return !(this->puyo == NULL);
}