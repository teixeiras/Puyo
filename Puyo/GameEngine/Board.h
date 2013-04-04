//
//  Board.h
//  Puyo
//
//  Created by Filipe Teixeira on 4/3/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#ifndef __Puyo__Board__
#define __Puyo__Board__

#include <iostream>

#define BOARD_WIDTH 6
#define BOARD_HEIGHT 12

#include "Piece.h"
#include "Puyo.h"

class Board
{
    Piece pieces[BOARD_WIDTH][BOARD_HEIGHT];
    Puyo  *activePuyo[2];
    bool  colided[2];
public:
    void initGame();
    void generateNewPuyo();
    bool iterate(int direction);
    
    Piece * getPieces();
    
    void shiftLeft();
    void shiftRight();
    void setDown();
    
    bool hasCollided();

};
#endif /* defined(__Puyo__Board__) */
