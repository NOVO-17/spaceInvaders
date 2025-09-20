#include <raylib.h>
#include "game.hpp"
#include <string>

std::string FormatWithLeadingZeros(int number, int width){
    std::string numbertext = std::to_string(number);
    int leadingZeros = width - numbertext.length();
    if (leadingZeros > 0) {
        numbertext = std::string(leadingZeros, '0') + numbertext;
    }
    return numbertext;
}

int main(){

    Color grey = {29, 29, 27, 255};
    Color yellow = {243, 216, 63, 255};
    int offset = 50;
    int windowWidth = 750;
    int windowHeight = 700;
    InitWindow(windowWidth + offset, windowHeight + 2 * offset, "Space Invaders");

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    Texture2D spaceShipImage = LoadTexture("Graphics/spaceShip.png");
    SetTargetFPS(60);
    game game;
    
    while (WindowShouldClose() == false)
    {
        game.inputHandle();
        game.update();
        BeginDrawing();
        ClearBackground(grey);
        DrawRectangleRoundedLinesEx({10, 10, 780, 780}, 0.18f, 20, 2, yellow);
        DrawLineEx({25,730}, {775, 730}, 3, yellow);
        if(game.run){
            DrawTextEx(font, "LEVEL 01", {570, 740}, 34, 2, yellow);
        }else{
            DrawTextEx(font, "GAME OVER", {570, 740}, 34, 2, yellow);
        }
        float x = 50.0;
        for( int i = 0; i < game.lives; i++){
            DrawTextureV(spaceShipImage,{x, 745}, WHITE);
            x += 50;
        }
        DrawTextEx(font, "SCORE", {50, 15}, 34, 2, yellow);
        std::string scoreText = FormatWithLeadingZeros(game.score, 5);
        DrawTextEx(font, scoreText.c_str(), {50, 40}, 34, 2, yellow);

        DrawTextEx(font, "HIGH SCORE", {570, 15}, 34, 2, yellow);
        std::string highText= FormatWithLeadingZeros(game.HighScore, 5);
        DrawTextEx(font, highText.c_str(), {655, 40}, 34, 2, yellow);

        game.draw();
        EndDrawing();
    }

    CloseWindow();
}