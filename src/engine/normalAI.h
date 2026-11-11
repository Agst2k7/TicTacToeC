#ifndef NORMAL_AI_H
#define NORMAL_AI_H

#include "../game/Board/Board.h"
#include "../game/Board/Piece.h"
#include "../game/game.h"

#include <stdlib.h>

int searchPossibleMovesNormal(const 
    struct Board *board, struct Pos *possible_moves, size_t *arr_size);

int chooseRandomMoveNormal(const struct Pos *possible_moves, size_t *arr_size, struct Pos *choosed_pos);

int validateMoves(
    struct Board *test_board,
    const struct Board *board,
    const enum Piece *team,
    const struct Pos *possible_moves_arr,
    size_t *p_moves_arr_size,
    struct Pos *good_moves_arr,
    size_t *g_moves_arr_size
);

int normalAiMove(const struct Board *board, const enum Piece *team,struct Pos *move);

#endif