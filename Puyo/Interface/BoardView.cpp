//
//  BoardView.cpp
//  Puyo
//
//  Created by Filipe Teixeira on 4/3/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#include "BoardView.h"
#include "EventManager.h"
#include "Event.h"


Uint32 tickHandler(Uint32 interval, void *param)
{
    
    BoardView * boardView = (BoardView *)param;
    if (!boardView->gameRunning()) {
        boardView->drawAll();
        boardView->gameOver();
        boardView->stopTick();
        return 400;
    }
    boardView->tick();
    
    return  400;
}

Uint32 drawHandler(Uint32 interval, void *param)
{
    BoardView * boardView = (BoardView *)param;
    if (!boardView->gameRunning()) {
        boardView->stopDrawAll();
        return 100;
    }
    boardView->drawAll();
    
    return 100;
}

void gameOverEvent(void * argument)
{
    std::cout<<"EndOfGame"<<std::endl;
}
BoardView::BoardView(Board * board, GameInterface * gameInterface)
{
    this->board = board;
    this->board->initGame();
    this->gameInterface = gameInterface;
    
    this->puyo_image[PUYO_TYPE_YELLOW] = this->gameInterface->load_image_with_alpha("puyo_yellow.bmp");
    this->puyo_image[PUYO_TYPE_PURPLE] = this->gameInterface->load_image_with_alpha("puyo_purple.bmp");
    this->puyo_image[PUYO_TYPE_GREEN] = this->gameInterface->load_image_with_alpha("puyo_green.bmp");
    this->puyo_image[PUYO_TYPE_BLUE] = this->gameInterface->load_image_with_alpha("puyo_blue.bmp");
    this->puyo_image[PUYO_TYPE_RED] = this->gameInterface->load_image_with_alpha("puyo_red.bmp");

  //  Event<BoardView> * endOfGame = new Event<BoardView> (END_OF_GAME);
  //  endOfGame->addObserver(EventCallback<BoardView>((void *)&gameOverEvent,this));
   // endOfGame->execute();
}

bool BoardView::gameRunning()
{
    return isGameRunning;
}

void BoardView::stopTick()
{
    SDL_RemoveTimer(this->tickTimer);
}

void BoardView::stopDrawAll()
{
    SDL_RemoveTimer(this->drawTimer);
}


int BoardView::tick()
{
    if (!board->iterate(0)){
        board->generateNewPuyo();
    }
    if (board->endOfGame()){
        isGameRunning = false;
    }
    return 1;
}


void BoardView::init()
{
    this->drawBackground();
    tickTimer = SDL_AddTimer(400,tickHandler,this);
    drawTimer = SDL_AddTimer(100,drawHandler,this);
    while(this->gameRunning()) {
        SDL_Delay(200);
    }
    isGameRunning = true;
    this->keyboardHandler();
}


BoardView::~BoardView()
{
    for (int i=0 ; i< 5;i++) {
        SDL_FreeSurface(this->puyo_image[i]);
    }
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
                    case SDLK_z:
                        this->rotateLeft();
                        break;
                    case SDLK_x:
                        this->rotateRight();
                        break;
                    case SDLK_DOWN:
                        this->goDown();
                        break;
                    case SDLK_LEFT:
                        this->goLeft();
                        break;
                    case SDLK_RIGHT:
                        this->goRight();
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
}

void BoardView::rotateLeft()
{
    this->board->rotateLeft();
    this->drawAll();
}

void BoardView::rotateRight()
{
    this->board->rotateRight();
    this->drawAll();
}

void BoardView::goLeft()
{
    this->board->moveLeft();
    this->drawAll();
}

void BoardView::goRight()
{
    this->board->moveRight();
    this->drawAll();
}
void BoardView::goDown()
{
    if (!board->iterate(0)){
        board->generateNewPuyo();
    }
    this->drawAll();
}


void BoardView::drawBackground()
{
    SDL_Rect rect = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
    SDL_FillRect(this->gameInterface->getScreen(), &rect, SDL_MapRGB(this->gameInterface->getScreen()->format, 20, 20, 200));
    
}


void BoardView::drawScore()
{
    
}

void BoardView::drawPuyo()
{
    Piece * pieces = board->getPieces();
    SDL_Rect rect;
    Uint16 width = PUYO_SIZE * BOARD_WIDTH;
    Uint16 height = PUYO_SIZE * BOARD_HEIGHT;
    
    Sint16 position[2];
    position[0] = (SCREEN_WIDTH - width) / 2;
    position[1] = (SCREEN_HEIGHT - height) / 2;
    rect = {position[0],position[1],width,height};
    
    SDL_FillRect(this->gameInterface->getScreen(), &rect, SDL_MapRGB(this->gameInterface->getScreen()->format, 200, 200, 200));
    
    
    for (int j = BOARD_HEIGHT ; j > 0; j--) {
        for (int i=0; i < BOARD_WIDTH;  i++) {
            Piece piece = *(pieces + j- 1 + i* BOARD_HEIGHT);
            if (piece.hasPiece()) {
                
                Sint16 poyoPosition[2];
                poyoPosition[0] = position[0] +  PUYO_SIZE * i;
                poyoPosition[1] = position[1] + height - PUYO_SIZE * j;
                
                this->gameInterface->apply_surface( poyoPosition[0], poyoPosition[1], this->puyo_image[piece.getPuyo()->getPuyoType()], this->gameInterface->getScreen() );
            }
        }
    }
    
    if( SDL_Flip( this->gameInterface->getScreen() ) == -1 )
    {
        return ;
    }
}

void BoardView::drawAll()
{
    this->drawPuyo();
}


void BoardView::gameOver()
{
    Uint16 width = SCREEN_WIDTH /3 * 2;
    Uint16 height = SCREEN_HEIGHT /3 * 2;
    
    Sint16 position [2];
    position[0] =(SCREEN_WIDTH  - width) / 2;
    position[1] =(SCREEN_HEIGHT  - height) / 2;
    
    SDL_Rect rect = {position[0],position[1] , width, height };
    SDL_FillRect(this->gameInterface->getScreen(), &rect, SDL_MapRGB(this->gameInterface->getScreen()->format, 0xF0, 0x0, 0xF0));

    
    if( SDL_Flip( this->gameInterface->getScreen() ) == -1 )
    {
        return ;
    }
}
