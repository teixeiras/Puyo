//
//  main.cpp
//  PuyoWindow
//
//  Created by Filipe Teixeira on 4/4/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#include <iostream>
#include <SDL/SDL.h>
#include "SDLMain.h"
#include "Board.h"
#include "StartScene.h"
#include "GameInterface.h"

int main(int argc,  char * argv[])
{

    Board * board = new Board();
    GameInterface * gameInterface = new GameInterface();
    if (!gameInterface->init()) {
        std::cout<<"SDL init failed"<<std::endl;
        return -1;
    }
    StartScene * startScene = new StartScene(gameInterface);
    gameInterface->end();
}

