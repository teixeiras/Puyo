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
    this->generateNewPuyo();
    for (int i =0 ; i < BOARD_WIDTH; i++) {
        for (int j =0 ; j < BOARD_HEIGHT; j++) {
            int position[2] = {i,j};
            pieces[i][j].setPosition(position);
        }
    }
}

void Board::generateNewPuyo()
{
    colided[0] = colided[1] = false;
    int position =  BOARD_WIDTH / 2;
    srand ((int)time(NULL));
    for (int i =0; i < 2; i++) {

        activePuyo[i] = new Puyo(static_cast<PUYO_TYPE>(rand() % 5));
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
    
    int * position1 = activePuyo[0]->getPosition();
    int * position2 = activePuyo[1]->getPosition();
    int first = 0;
    if (position1[1] < position2[1]) {
        first = 1;
    } else {
        first = 0;
    }
    
    
    for (int j =0; j < 2; j++) {
        int i = j;
        if (!first) {
            i = !j;
        }
        int *position = activePuyo[i]->getPosition();
        if (position[1] - 1< 0) {
            colided[i] = true;
            if (colided[!i])
                return false;
            continue;
        }
        
        if (this->pieces[position[0] + direction][position[1] - 1].hasPiece()) {
            if (!colided[i]) {
                colided[i] = true;
                do {
                        this->iterate(0);
                }while(colided[!i] == false);
                this->detectCombinations(&this->pieces[position[0] + direction][position[1] - 1]);

                return false;
            }
            if (position[1] >= BOARD_HEIGHT -1){
                gameover = true;
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


void Board::detectNearPieces(Piece * piece, std::vector<Piece *> * memory)
{
    if (std::find(memory->begin(), memory->end(), piece)!=memory->end()) {
        return;
    }
    memory->push_back(piece);
    
    //down Piece
    if (piece->getPosition()[1] - 1 >= 0) {
        Piece * tmpPiece = &pieces[piece->getPosition()[0]][piece->getPosition()[1] - 1];
        if (tmpPiece->getPuyo()) {
            if (tmpPiece->getPuyo()->getPuyoType() == piece->getPuyo()->getPuyoType()) {
                this->detectNearPieces(tmpPiece, memory);
                
            }
        }
    }
    //left Piece
    if (piece->getPosition()[0] - 1 >= 0) {
        Piece * tmpPiece = &pieces[piece->getPosition()[0] - 1][piece->getPosition()[1]];
        if (tmpPiece->getPuyo()) {
            if (tmpPiece->getPuyo()->getPuyoType() == piece->getPuyo()->getPuyoType()) {
                this->detectNearPieces(tmpPiece, memory);
            }
        }
    }
    
    //up Piece
    if (piece->getPosition()[1] + 1 < BOARD_HEIGHT) {
        Piece * tmpPiece = &pieces[piece->getPosition()[0]][piece->getPosition()[1] + 1];
        if (tmpPiece->getPuyo()) {
            if (tmpPiece->getPuyo()->getPuyoType() == piece->getPuyo()->getPuyoType()) {
                this->detectNearPieces(tmpPiece, memory);
            }
        }
    }
    //right Piece
    if (piece->getPosition()[0] + 1 < BOARD_WIDTH) {
        Piece * tmpPiece = &pieces[piece->getPosition()[0] + 1][piece->getPosition()[1]];
        if (tmpPiece->getPuyo()) {
            if (tmpPiece->getPuyo()->getPuyoType() == piece->getPuyo()->getPuyoType()) {
                this->detectNearPieces(tmpPiece, memory);
            }
        }
    }
}

void Board::detectCombinations(Piece * piece)
{
    std::vector<Piece *> * memory = new std::vector<Piece *>();
    std::vector<Puyo *> * puyos = new std::vector<Puyo *>();
    this->detectNearPieces(piece, memory);
    if (memory->size() >= 3) {
        std::vector<Piece *>::iterator pieceIterator = memory->begin();
        for (;pieceIterator != memory->end(); pieceIterator ++ ) {
            Piece * piece = *pieceIterator;
            piece->removePuyo();
            
            if (!(std::find(puyos->begin(), puyos->end(), piece->getPuyo())!=puyos->end())) {
                puyos->push_back(piece->getPuyo());
            }
        }
        
        std::vector<Puyo *>::iterator puyoIterator = puyos->begin();
        for (;puyoIterator != puyos->end(); puyoIterator ++ ) {
            Puyo * puyo = * puyoIterator;
            
            if (pieces[puyo->getPosition()[0]][puyo->getPosition()[1]].hasPiece()) {
                this->detectCombinations(&pieces[puyo->getPosition()[0]][puyo->getPosition()[1]]);
            }
        }

    }
}

void Board::moveOnDirection(int direction)
{
    bool isValid = true;
    for (int i =0; i < 2; i++) {
        int *position = activePuyo[i]->getPosition();
        if (!(position[0] + direction >= 0 &&
              !(this->pieces[position[0] + direction][position[1]].hasPiece()
                && (this->pieces[position[0] + direction][position[1]].getPuyo()!=activePuyo[!i]))
              )){
    
            isValid = false;
        }
    }
    if (isValid) {
        
        int *position1 = activePuyo[0]->getPosition();
        int *position2 = activePuyo[1]->getPosition();
        
        this->pieces[position1[0]][position1[1]].removePuyo();
        this->pieces[position2[0]][position2[1]].removePuyo();

        position1[0] += direction;
        this->pieces[position1[0]][position1[1]].addPuyo(activePuyo[0]);
        
        position2[0] += direction;
        this->pieces[position2[0]][position2[1]].addPuyo(activePuyo[1]);
    }
}
void Board::moveLeft()
{
    this->moveOnDirection(-1);
}

void Board::moveRight()
{
    this->moveOnDirection(1);
}

void Board::rotateLeft()
{
    bool isValid = true;
    
    int *position = activePuyo[0]->getPosition();
    int trans[2];
    if (activePuyo[1]->getPosition()[0] == position[0]) {
        //in vertical line
        if (activePuyo[1]->getPosition()[1] - position[1]>0) {
            //piece for rotation is down go right
            trans[0] = 1;
            trans[1] = 1;
        } else {
            //piece for rotation is up go left
            trans[0] = -1;
            trans[1] = -1;
        }
    } else{
        //in horizontal line
        if (activePuyo[1]->getPosition()[0] - position[0]>0) {
            //piece for rotation is on right go up
            trans[0] = 1;
            trans[1] = -1;
        } else {
            //piece for rotation is on left go down
            trans[0] = -1;
            trans[1] = 1;
        }
    }

    if (position[0] + trans[0] >= 0 && position[1] + trans[1] >= 0 && !this->pieces[position[0] + trans[0]][position[1] + trans[1]].hasPiece()) {
        isValid = true;
    } else {
        isValid = false;
    }

    if (isValid) {
        int *position = activePuyo[0]->getPosition();
        this->pieces[position[0]][position[1]].removePuyo();
        position[0] += trans[0];
        position[1] += trans[1];
        this->pieces[position[0]][position[1]].addPuyo(activePuyo[0]);
    }
}

void Board::rotateRight()
{
    bool isValid = true;
    
    int *position = activePuyo[1]->getPosition();
    int trans[2];
    if (activePuyo[0]->getPosition()[0] == position[0]) {
        //in vertical line
        if (activePuyo[0]->getPosition()[1] - position[1]>0) {
            //piece for rotation is down go right
            trans[0] = 1;
            trans[1] = 1;
        } else {
            //piece for rotation is up go left
            trans[0] = -1;
            trans[1] = -1;
        }
    } else{
        //in horizontal line
        if (activePuyo[0]->getPosition()[0] - position[0]>0) {
            //piece for rotation is on right go up
            trans[0] = 1;
            trans[1] = -1;
        } else {
            //piece for rotation is on left go down
            trans[0] = -1;
            trans[1] = 1;
        }
    }
    
    if (position[0] + trans[0] >= 0 && position[1] + trans[1] >= 0 && !this->pieces[position[0] + trans[0]][position[1] + trans[1]].hasPiece()) {
        isValid = true;
    } else {
        isValid = false;
    }
    
    if (isValid) {
        int *position = activePuyo[1]->getPosition();
        this->pieces[position[0]][position[1]].removePuyo();
        position[0] += trans[0];
        position[1] += trans[1];
        this->pieces[position[0]][position[1]].addPuyo(activePuyo[1]);
    }}

void Board::moreStep()
{
    this->iterate(0);
}


bool Board::hasCollided()
{
    return (colided[1] & colided[0]);
}

Piece * Board::getPieces()
{
    return *this->pieces;
}