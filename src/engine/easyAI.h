#ifndef EASY_AI_H
#define EASY_AI_H

#include "../game/Board/Board.h"
#include <stdlib.h>

int searchPossibleMovesEasy(struct Board *board, struct Pos *possible_moves, size_t *arr_size);

int chooseRandomMoveEasy(const struct Pos *possible_moves, size_t *arr_size, struct Pos *choosed_pos);

int easyAiMove(struct Board *board, struct Pos *move);

#endif