#include "inputs.h"

void cleanBuffer(void){
    int c;
    while ((c = getchar()) != '\n');
}


int takePosInput(struct Pos *pos) {
    char input[3];

    while (1) {
        printf("Insert a position (ex.: A2, b1): ");

        if (scanf("%2s", input) != 1) {
            printf("Invalid input, try again:\n");
            cleanBuffer();
            continue;
        }

        cleanBuffer();

        if (
            (input[0] != 'a' && input[0] != 'b' && input[0] != 'c' &&
             input[0] != 'A' && input[0] != 'B' && input[0] != 'C') ||
            (input[1] < '1' || input[1] > '3') ||
            input[2] != '\0'
        ) {
            printf("Invalid input, try again:\n");
            pressEnterToContinue();
            continue;
        }

        break;
    }

    if (input[0] == 'a' || input[0] == 'A')
        pos->x = 1;
    else if (input[0] == 'b' || input[0] == 'B')
        pos->x = 2;
    else
        pos->x = 3;

    pos->y = input[1] - '0';

    return 0;
}
