#include <iostream>
#include <raylib.h>
#include <vector>
#include <ctime>
#include <cmath>
#include <string>
#include <unordered_map>

#include "include/constants.h"
#include "include/utils.h"
#include "include/resource.h"
#include "include/random.h"
#include "include/game-state.h"
#include "include/button.h"

using namespace std;

struct Game {
    GameState currentState = GameState::MainTitle;
    
    Game(Resources& resources) {}
};

int main() {
    
    InitWindow(Constants::windowX, Constants::windowY, "Química");
    
    const int fps = 60;
    SetTargetFPS(fps);
    
    InitAudioDevice();
    Resources* resources = new Resources();
    Game game = {resources};
    
    // Button b1 = {{20, 20}, 5.f, {30, 15}, 50, "Teste", WHITE, BLACK, WHITE};
        
    while (!WindowShouldClose()) {
        
        BeginDrawing();
        
        ClearBackground(BLACK);
        if (game.currentState == GameState::MainTitle) {
            // bool changeColor = Utils::timer(GetTime(), start, Constants::blinkIterval);
            // if (changeColor) ++counter;
            // game.mainTitle(*resources, counter % 2 == 0 ? WHITE : Color{152, 27, 36});
            if (IsKeyPressed(KEY_ENTER)) {
                game.currentState = GameState::Playing;
            }
        } else if (game.currentState == GameState::Playing) {
            // game.render();
        } else if (game.currentState == GameState::GameOver) {
            // DrawText("Game Over", 100, 140, 80, YELLOW);
            // DrawText("Pressione Enter para começar!", 95, 430, 35, WHITE);
            // if (IsKeyPressed(KEY_ENTER)) {
            //     game.currentState = GameState::Playing;
            // }            
        }
        
        // b1.draw();
        
        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}
