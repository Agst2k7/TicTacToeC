#include "game.h"

int thereIsAPiece(const struct Board *board, const struct Pos *pos){
    return !(board->places[pos->x-1][pos->y-1] == NONE);
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

    short int round = 1;

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
        ++round;
    }
    return winner;
}

enum Piece playEasyAi(void){
    struct Board board = {0};
    
    struct Pos pos = {0};
    
    enum Piece currentTeam = X;
    enum Piece winner = NONE;

    short int round = 1;

    while(round <= 9){
        clearScr();
        printBoard(&board);
        takePosInput(&pos);
        if(makeMove(&board, &currentTeam, &pos) != 0){
            puts("Invalid Position, try again:");
        };
        clearScr();
        printBoard(&board);
        if(DidAnyoneWin(&board)){
            winner = currentTeam;
            clearScr();
            printBoard(&board);
            //printEndGame(&winner);
            break;
        }
        swapTeams(&currentTeam);
        ++round;
        sleep(1);
        easyAiMove(&board, &pos);
        if(makeMove(&board, &currentTeam, &pos) != 0){
            puts("Invalid Position, try again:");
        };
        clearScr();
        printBoard(&board);
        if(DidAnyoneWin(&board)){
            winner = currentTeam;
            //printEndGame(&winner);
            break;
        }
        swapTeams(&currentTeam);
        round++;
    }
    return winner;
}

enum Piece playNormalAi(void){
    struct Board board = {0};
    
    struct Pos pos = {0};
    
    enum Piece currentTeam = X;
    enum Piece winner = NONE;

    short int round = 1;

    while(round <= 9){
        clearScr();
        printf("Round: %d", round);
        printBoard(&board);
        takePosInput(&pos);
        if(makeMove(&board, &currentTeam, &pos) != 0){
            puts("Invalid Position, try again:");
        };
        clearScr();
        printf("Round: %d", round);
        printBoard(&board);
        if(DidAnyoneWin(&board)){
            winner = currentTeam;
            clearScr();
            printBoard(&board);
            //printEndGame(&winner);
            break;
        }
        if(round == 9){ return NONE; }
        swapTeams(&currentTeam);
        ++round;
        sleep(1);
        normalAiMove(&board, &currentTeam, &pos);
        if(makeMove(&board, &currentTeam, &pos) != 0){
            puts("Invalid Position, try again:");
        };
        clearScr();
        printf("Round: %d", round);
        printBoard(&board);
        if(DidAnyoneWin(&board)){
            winner = currentTeam;
            //printEndGame(&winner);
            break;
        }
        swapTeams(&currentTeam);
        round++;
    }
    return winner;
}
