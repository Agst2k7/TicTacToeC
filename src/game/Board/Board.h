#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"

struct Board{
    enum Piece places[3][3];
};

struct Pos{
    short int x;
    short int y;
};

#endif