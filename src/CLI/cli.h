#ifndef CLI_H
#define CLI_H

#include <stdio.h>

#include "../game/Board/Board.h"

void clearScr(void);

void pressEnterToContinue(void);


void printBoard(struct Board *board);

#endif