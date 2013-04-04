//
//  StartScene.h
//  PuyoWindow
//
//  Created by Filipe Teixeira on 4/4/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#ifndef __PuyoWindow__StartScene__
#define __PuyoWindow__StartScene__

#include <iostream>
#include "GameInterface.h"
#include "Button.h"
class StartScene
{
    GameInterface * gameInterface;
    Button * startGame;
public:
    StartScene(GameInterface * gameInterface);
    void drawScene();
    void keyboardHandler();
    void goUp();
    void goDown();
    void select();
};
#endif /* defined(__PuyoWindow__StartScene__) */
