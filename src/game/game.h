#ifndef GAME_H
#define GAME_H

#include "Board/Board.h"
#include "../CLI/cli.h"
#include "../CLI/inputs.h"
#include "../engine/easyAI.h"

int thereIsAPiece(struct Board *board, const struct Pos *pos);

int makeMove(struct Board *board, const enum Piece *piece, const struct Pos *pos);

int DidAnyoneWin(const struct Board *board);

void swapTeams(enum Piece *currentTeam);

enum Piece play(void);

enum Piece playEasyAi(void);

#endif