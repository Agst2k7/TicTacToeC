#include <stdio.h>
#include <stdlib.h>

#include "game/Board/Board.h"
#include "CLI/cli.h"
#include "CLI/inputs.h"
#include "game/game.h"

int main(){

    struct Board board = {0};

    struct Pos pos;
    enum Piece piece = X;

    enum Piece winner = NONE;
    enum Piece currentTeam = X;

    winner = play();
    
    return 0;
}