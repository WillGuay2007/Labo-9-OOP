#include "entrypoint.h"
#include <raylib.h>
#include "Classes.h"

void raylib_start(void){

    SetTargetFPS(60);
    MyGame* game = new MyGame();
    InitWindow(780, 420, "Labo_9");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
}