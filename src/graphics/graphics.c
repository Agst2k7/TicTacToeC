#include "graphics.h"

#define WINDOW_SIZE_X 800
#define WINDOW_SIZE_Y 1000

void drawBoard(void) {
    //DrawLine(startPosX, startPosY, endPosX, endPosY, color);
    DrawLine(200, 0, 200, 600, BLACK);
    DrawLine(400, 0, 400, 600, BLACK);

    DrawLine(10, 200, WINDOW_SIZE_X-10, 200, BLACK);
    DrawLine(10, 400, WINDOW_SIZE_X-10, 400, BLACK);
}

void play_graphics(){
    InitWindow(WINDOW_SIZE_X, WINDOW_SIZE_Y, "Tic-Tac-ToeC");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // 1. Processar entradas
        // 2. Atualizar estado do jogo
        // 3. Renderizar interface

        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Desenhar tabuleiro e símbolos
        drawBoard();

        EndDrawing();
    }

    CloseWindow();

}