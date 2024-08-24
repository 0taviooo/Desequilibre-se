#include <iostream>
#include <raylib.h>
#include <vector>
#include <ctime>
#include <cmath>
#include <string>
#include <unordered_map>

#include "include/Constants.h"
#include "include/utils.h"
#include "include/resource.h"
#include "include/random.h"
#include "include/game-state.h"
#include "include/button.h"

using namespace std;

struct Game {
    GameState currentState = GameState::MainTitleScreen;
    
    Game(Resources& resources) {}
    
    void mainTitle(Color startColor);
};

void Game::mainTitle(Color startColor) {
    DrawText("(Des)Equilibrados!", 100, 140, FontSize::h1, WHITE);
    DrawText("Pressione Enter para começar!", 95, 430, FontSize::h2, startColor);
    DrawText("IFCE Itapipoca", 284, 600, FontSize::note, WHITE);
}

int main() {
    
    InitWindow(GameConstants::windowX, GameConstants::windowY, "(Des)Equilibrados");
    
    const int fps = 60;
    SetTargetFPS(fps);
    
    InitAudioDevice();
    Resources* resources = new Resources();
    Game game = {*resources};
    
    float start = GetTime();
    int counter = 0;
    
    // Button b1 = {{20, 20}, 5.f, {30, 15}, 50, "Teste", WHITE, BLACK, WHITE};
        
    while (!WindowShouldClose()) {
        
        BeginDrawing();
        
        ClearBackground(BLACK);
        
        if (game.currentState == GameState::MainTitleScreen) {
            bool changeColor = Utils::timer(GetTime(), start, GameConstants::blinkIterval);
            if (changeColor) ++counter;
            game.mainTitle(counter % 2 == 0 ? WHITE : BLACK);
            if (IsKeyPressed(KEY_ENTER)) {
                game.currentState = GameState::PlayingScreen;
            }
        }
        else if (game.currentState == GameState::PlayingScreen) {
            // game.render();
        }
        else if (game.currentState == GameState::GameOverScreen) {
            // DrawText("Game Over", 100, 140, 80, YELLOW);
            // DrawText("Pressione Enter para começar!", 95, 430, 35, WHITE);
            if (IsKeyPressed(KEY_ENTER)) {
                game.currentState = GameState::PlayingScreen;
            }            
        }
        
        // b1.draw();
        
        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}
