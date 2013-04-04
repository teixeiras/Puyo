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


class BoardView
{
public:
    BoardView();
    void drawAll(Board * board);
};
#endif /* defined(__Puyo__BoardView__) */
