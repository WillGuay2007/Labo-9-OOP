#include "entrypoint.h"
#include <raylib.h>
#include "Classes.h"

void raylib_start(void){

    SetTargetFPS(60);
    InitWindow(780, 420, "Labo_9");
    MyGame* game = new MyGame();
    game->AddObject(new Circle(250,100,5,BLUE));
    game->AddObject(new Circle(100,300,50,YELLOW));
    game->AddObject(new Circle(250,430,25,RED));
    game->AddObject(new line(0, WIDTH, 0, HEIGHT, BLUE));
    game->AddObject(new line(0, WIDTH, HEIGHT, 0, YELLOW));
    game->AddObject(new rect(200, 200, 50, 50, GREEN));
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        game->Run();
        EndDrawing();
    }
}