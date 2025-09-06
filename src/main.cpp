#include <raylib.h>
#include "game.hpp"

int main(){

    Color grey = {29, 29, 27, 255};

    int windowWidth = 750;
    int windowHeight = 700;
    InitWindow(windowWidth, windowHeight, "Space Invaders");

    SetTargetFPS(60);
    game game;
    

    while (WindowShouldClose() == false)
    {
        game.inputHandle();
        game.update();

        BeginDrawing();

        ClearBackground(grey);
        game.draw();
        
        
        EndDrawing();

    }
    
    CloseWindow();
}