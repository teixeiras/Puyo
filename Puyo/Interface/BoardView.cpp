//
//  BoardView.cpp
//  Puyo
//
//  Created by Filipe Teixeira on 4/3/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#include "BoardView.h"


Uint32 tick(Uint32 interval, void *param)
{
    BoardView * boardView = (BoardView *)param;
    boardView->tick();
    if (boardView->gameRunning()) {
        SDL_AddTimer(10,tick,boardView);
    }
    return 1;
}
int main_thread(void * data)
{
    BoardView * boardView = (BoardView *)data;
    SDL_AddTimer(10,tick,boardView);
    while(boardView->gameRunning()) {
        SDL_Delay(200);
    }
    return 1;
}

BoardView::BoardView(Board * board, GameInterface * gameInterface)
{
    this->board = board;
    this->board->initGame();
    this->gameInterface = gameInterface;
    gameThread = SDL_CreateThread(main_thread, this );
    isGameRunning = true;
    this->keyboardHandler();
}

bool BoardView::gameRunning()
{
    return isGameRunning;
}

int BoardView::tick()
{
    board->iterate(0);
    this->drawAll();
    return 1;
}


void BoardView::init()
{
    
}


void BoardView::drawAll()
{
    Piece * pieces = board->getPieces();
    for (int i=0; i< BOARD_WIDTH; i ++) {
            std::cout<<"#";
    }
    std::cout<<std::endl;
    for (int j = BOARD_HEIGHT ; j > 0; j--) {
        for (int i=0; i < BOARD_WIDTH;  i++) {
            Piece piece = *(pieces + j- 1 + i* BOARD_HEIGHT);
            std::cout<<(piece.hasPiece()?"*":" ");
        }
        std::cout<<std::endl;
    }
    for (int i=0; i< BOARD_WIDTH; i ++) {
        std::cout<<"#";
    }
    std::cout<<std::endl;
    
}

void BoardView::keyboardHandler()
{
    bool quit = false;
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
                        this->rotateLeft();
                        break;
                    case SDLK_DOWN:
                        this->rotateRight();
                        break;
                    case SDLK_LEFT:
                        this->goLeft();
                        break;
                    case SDLK_RIGHT:
                        this->goRight();
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
        }
    }
}

void BoardView::rotateLeft()
{
    this->board->rotateLeft();
}

void BoardView::rotateRight()
{
    this->board->rotateRight();
}

void BoardView::goLeft()
{
    this->board->moveLeft();}

void BoardView::goRight()
{
    this->board->moveRight();
}

