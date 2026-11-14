#include "cli.h"

void clearScr(void){
    printf("\033[3J"); 
    printf("\033[2J"); 
    printf("\033[H");   
    fflush(stdout); 
}

void pressEnterToContinue(void){
    printf("\nPress Enter to continue...");
    fflush(stdout);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void printBoard(struct Board *board){
    for(int i=0; i<3; ++i){
        printf("\n");
        for(int j=0; j<3; ++j){
            if(j == 0 && i == 0){ printf("A "); }
            else if(j == 0 && i == 1){ printf("B "); }
            else if(j == 0 && i == 2){ printf("C "); }
            if(j != 0){ printf(" "); }
            if(board->places[i][j] == NONE){ printf("-"); }
            else if(board->places[i][j] == X){ printf("X"); }
            else if(board->places[i][j] == O){ printf("O"); }
        }
    }
    printf("\n");
    printf("  1 2 3\n");
}
