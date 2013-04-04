//
//  BoardView.h
//  Puyo
//
//  Created by Filipe Teixeira on 4/3/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#ifndef __Puyo__BoardView__
#define __Puyo__BoardView__

#include <iostream>
#include "Board.h"
#include "GameInterface.h"

#include "SDL/SDL.h"
#include <string>


class BoardView
{
    Board * board;
    GameInterface * gameInterface;
public:
    BoardView(Board * board, GameInterface * gameInterface);
    void init();
    void drawAll();
};
#endif /* defined(__Puyo__BoardView__) */
