#include "easyAI.h"

int searchPossibleMoves(struct Board *board, struct Pos *possible_moves, short int *arr_size){
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

int chooseRandomMove(const struct Pos *possible_moves, short int *arr_size, struct Pos *choosed_pos){
    *choosed_pos = possible_moves[rand() % (*arr_size)];
    return 0;
}

int easyAiMove(struct Board *board, struct Pos *move){
    struct Pos possible_moves[9] = {0};
    short int p_moves_size = 0;
    struct Pos choosed_move;
    
    searchPossibleMoves(board, possible_moves, &p_moves_size);

    chooseRandomMove(possible_moves, &p_moves_size, &choosed_move);

    *move = choosed_move;

    return 0;
}