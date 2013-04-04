//
//  Board.cpp
//  Puyo
//
//  Created by Filipe Teixeira on 4/3/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#include "Board.h"


void Board::initGame()
{
    
}

void Board::generateNewPuyo()
{
    int position =  BOARD_WIDTH / 2;
    for (int i =0; i < 2; i++) {
        activePuyo[i] = new Puyo;
        activePuyo[i]->getPosition()[0] = position;
        activePuyo[i]->getPosition()[1] = BOARD_HEIGHT - (i + 1 );
        this->pieces[activePuyo[i]->getPosition()[0]]
                    [activePuyo[i]->getPosition()[1]].addPuyo(activePuyo[i]);
    }
    
}

void Board::shiftLeft()
{
    this->iterate(1);
}

void Board::shiftRight()
{
    this->iterate(-1);
}
void Board::setDown()
{
    this->iterate(0);
}
bool Board::iterate(int direction)
{
    for (int i =0; i < 2; i++) {
        
        int *position = activePuyo[i]->getPosition();
        if (position[1] - 1< 0) {
            continue;
        }
        
        if (this->pieces[position[0] + direction][position[1] - 1].hasPiece()) {
            if (!colided[i]) {
                colided[i] = true;
                do {
                    this->iterate(0);
                }while(colided[!i] == false);
            }
            continue;
        }
        
        this->pieces[position[0]][position[1]].removePuyo();
        position[1] --;
        position[0] -= direction;
        this->pieces[position[0]][position[1]].addPuyo(activePuyo[i]);
    }
    return true;
}

bool Board::hasCollided()
{
    return (colided[1] & colided[0]);
}

Piece * Board::getPieces()
{
    return *this->pieces;
}