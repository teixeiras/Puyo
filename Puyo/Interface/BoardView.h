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
#include <SDL/SDL_thread.h>

class BoardView
{
    Board * board;
    GameInterface * gameInterface;
    SDL_Thread * gameThread;
    bool isGameRunning;
    SDL_TimerID tickTimer, drawTimer;
public:
    BoardView(Board * board, GameInterface * gameInterface);
    void init();
    
    int tick();
    bool gameRunning();
    void stopTick();
    void stopDrawAll();
    void keyboardHandler();
    
    void rotateLeft();
    void rotateRight();

    void goLeft();
    void goRight();
    
    void drawAll();
    void gameOver();
    
};
#endif /* defined(__Puyo__BoardView__) */
