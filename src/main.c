#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game/Board/Board.h"
#include "CLI/cli.h"
#include "CLI/inputs.h"
#include "game/game.h"


int main(){

    srand(time(NULL));

    struct Board board = {0};
    struct Pos pos;

    enum Piece winner = NONE;
    enum Piece currentTeam = X;

    winner = playEasyAi();
    
    return 0;
}