#include "normalAI.h"

int searchPossibleMovesNormal(const struct Board *board, struct Pos *possible_moves, size_t *arr_size){
    struct Pos pos;
    *arr_size = 0;
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            if(board->places[i][j] == NONE){
                pos.x = i+1;
                pos.y = j+1;
                possible_moves[*arr_size] = pos;
                (*arr_size)++;
            }
        }
    }
    return 0;
}

int chooseRandomMoveNormal(const struct Pos *possible_moves, size_t *arr_size, struct Pos *choosed_pos){
    *choosed_pos = possible_moves[rand() % (*arr_size)];
    return 0;
}

int validateMoves(
    struct Board *test_board,
    const struct Board *board,
    const enum Piece *team,
    const struct Pos *possible_moves_arr,
    size_t *p_moves_arr_size,
    struct Pos *good_moves_arr,
    size_t *g_moves_arr_size
){
    //check if there is a winning move
    for(int i=0; i<*p_moves_arr_size; ++i){
        *test_board = *board;
        makeMove(test_board, team, possible_moves_arr+i);
        if(DidAnyoneWin(test_board) == 1){
            *g_moves_arr_size = 1;
            *good_moves_arr = *(possible_moves_arr+i);
            return 1;
        }
    }

    //check if there is a winning move for the opponent
    enum Piece temp_team = *team;
    swapTeams(&temp_team);
    for(int i=0; i<*p_moves_arr_size; ++i){
        *test_board = *board;
        makeMove(test_board, &temp_team, possible_moves_arr+i);
        if(DidAnyoneWin(test_board) == 1){
            *g_moves_arr_size = 1;
            *good_moves_arr = *(possible_moves_arr+i);
            return 1;
        }
    }

    //search for the center
    struct Pos center = {2, 2};
    if(thereIsAPiece(board, &center) == 0){
        *g_moves_arr_size = 1;
        *good_moves_arr = center;
        return 1;
    }

    for(int i=0; i<*p_moves_arr_size; ++i){
        (*g_moves_arr_size)++;
        *(good_moves_arr+i) = *(possible_moves_arr+i);
    }
}

int normalAiMove(const struct Board *board, const enum Piece *team,struct Pos *move){
    struct Board test_board;

    struct Pos possible_moves[9] = {0};
    size_t p_moves_size = 0;
    
    
    searchPossibleMovesNormal(board, possible_moves, &p_moves_size);

    /*printf("P_moves_size: %zu", p_moves_size);
    pressEnterToContinue();*/

    struct Pos good_moves[9] = {0};
    size_t g_moves_size = 0;

    struct Pos choosed_move;

    validateMoves(
        &test_board,
        board,
        team,
        possible_moves,
        &p_moves_size,
        good_moves,
        &g_moves_size
    );

    /*printf("P_moves_size: %zu", p_moves_size);
    printf("G_moves_size: %zu", g_moves_size);
    pressEnterToContinue();*/

    if(g_moves_size == 1){
        choosed_move = good_moves[0];
    }
    else if(g_moves_size > 1){
        chooseRandomMoveNormal(possible_moves, &p_moves_size, &choosed_move);
    }

    *move = choosed_move;
    return 0;
}