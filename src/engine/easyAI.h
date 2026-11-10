#ifndef EASY_AI_H
#define EASY_AI_H

#include "../game/Board/Board.h"
#include <stdlib.h>

int searchPossibleMoves(struct Board *board, struct Pos *possible_moves, short int *arr_size);

int chooseRandomMove(const struct Pos *possible_moves, short int *arr_size, struct Pos *choosed_pos);

int easyAiMove(struct Board *board, struct Pos *move);

#endif