//
//  BoardView.cpp
//  Puyo
//
//  Created by Filipe Teixeira on 4/3/13.
//  Copyright (c) 2013 João Tojo. All rights reserved.
//

#include "BoardView.h"
BoardView::BoardView()
{
    
}
void BoardView::drawAll(Board * board)
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
