#ifndef INPUTS_H
#define INPUTS_H

#include <stdio.h>

#include "../game/Board/Board.h"
#include "cli.h"

void cleanBuffer(void);

int takePosInputInt(struct Pos *pos);

int takePosInput(struct Pos *pos);

#endif