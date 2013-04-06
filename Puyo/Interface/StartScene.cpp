//
//  StartScene.cpp
//  PuyoWindow
//
//  Created by Filipe Teixeira on 4/4/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#include "StartScene.h"
#include "SoundManager.h"
#include "BoardView.h"
StartScene::StartScene(GameInterface * gameInterface)
{
    this->gameInterface = gameInterface;
    float position[2] = {static_cast<float>(SCREEN_WIDTH / 2 - 124.5) , static_cast<float>(SCREEN_HEIGHT / 2) -20 };
    startGame = new Button(this->gameInterface, "startGameNormal.bmp","startGameSelected.bmp", position);
    
    
    this->drawScene();
   
    this->keyboardHandler();
    
};

void StartScene::drawScene()
{
 
    SDL_Surface * background = this->gameInterface->load_image("main.bmp");
    this->gameInterface->apply_surface( 0, 100, background, this->gameInterface->getScreen() );
    this->gameInterface->apply_surface( SCREEN_WIDTH, 0, background, this->gameInterface->getScreen() );
    this->gameInterface->apply_surface( 0, SCREEN_HEIGHT, background, this->gameInterface->getScreen() );
    this->gameInterface->apply_surface( SCREEN_WIDTH, SCREEN_HEIGHT, background, this->gameInterface->getScreen() );
    
    this->startGame->button();
    
    if( SDL_Flip( this->gameInterface->getScreen() ) == -1 )
    {
        return ;
    }
    SDL_FreeSurface(background);
    SoundManager::getSoundManager()->playMusic("beggining_music.wav");
}


void StartScene::keyboardHandler()
{
    bool quit = false;
    bool game = false;
    SDL_Event event;

    while( quit == false )
    {
        //If there's an event to handle
        if( SDL_PollEvent( &event ) )
        {
            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //Set the proper message surface
                switch( event.key.keysym.sym )
                {
                    case SDLK_UP:
                        this->goDown();
                        break;
                    case SDLK_DOWN:
                        this->goUp();
                        break;
                    case SDLK_RETURN:
                        game = true;
                        quit = true;
                        break;
                    case SDLK_ESCAPE:
                        quit = true;
                    default:
                        break;
                }
            }
            
            //If the user has Xed out the window
            else if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
            SDL_Delay(100);
        }
    }
    if (game == true) {
        this->select();
    }
}

void StartScene::goDown()
{
    
}

void StartScene::goUp()
{
    
}
void StartScene::select()
{
    Board * board = new Board();
    BoardView * boardView = new BoardView(board, this->gameInterface);
    boardView->init();
    
}