#include "game.h"

int thereIsAPiece(struct Board *board, const struct Pos *pos){
    return !(board->places[pos->x][pos->y] == NONE);
}

int makeMove(struct Board *board, const enum Piece *piece, const struct Pos *pos){

    if(thereIsAPiece(board, pos)){ return 1; }

    board->places[(pos->x)-1][(pos->y)-1] = *piece;

    return 0;
}

int DidAnyoneWin(const struct Board *board){

    // verify diagonals
    if(board->places[0][0] != NONE && board->places[0][0] == board->places[1][1] && board->places[0][0] == board->places[2][2]){
            return 1;
    }
    if(board->places[0][2] != NONE && board->places[0][2] == board->places[1][1] && board->places[1][1] == board->places[2][0]){
            return 1;
    }

    //verify vertical and horizontal lines
    for(int i=0; i<3; ++i){
        if(board->places[i][0] != NONE && board->places[i][0] == board->places[i][1] && board->places[i][0] == board->places[i][2]){
            return 1;
        }
        if(board->places[0][i] != NONE && board->places[0][i] == board->places[1][i] && board->places[0][i] == board->places[2][i]){
            return 1;
        }
    }

    return 0;
}

void swapTeams(enum Piece *currentTeam){
    if(*currentTeam == X){
        *currentTeam = O;
    }
    else{
        *currentTeam = X;
    }
}


enum Piece play(void){
    struct Board board = {0};
    
    struct Pos pos = {0};
    
    enum Piece currentTeam = X;
    enum Piece winner = NONE;

    while(1){
        clearScr();
        printBoard(&board);
        takePosInput(&pos);
        makeMove(&board, &currentTeam, &pos);
        if(DidAnyoneWin(&board)){
            winner = currentTeam;
            clearScr();
            printBoard(&board);
            //printEndGame(&winner);
            break;
        }
        swapTeams(&currentTeam);
    }
    return winner;
}
