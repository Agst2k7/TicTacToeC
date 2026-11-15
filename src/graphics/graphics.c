#include "graphics.h"

void test(){
    InitWindow(600, 600, "Tic Tac Toe");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // 1. Processar entradas
        // 2. Atualizar estado do jogo
        // 3. Renderizar interface

        BeginDrawing();

        ClearBackground(RAYWHITE);

        // Desenhar tabuleiro e símbolos

        EndDrawing();
    }

    CloseWindow();

}