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
    
    void mainTitleScreen(Color startColor);
};

void Game::mainTitleScreen(Color startColor) {
    const char* label_t1 = "(Des)Equilibrados!";
    const char* label_t2 = "Pressione Enter para começar!";
    const char* label_t3 = "IFCE Itapipoca";
    DrawText(label_t1, Utils::centralize(MeasureText(label_t1, FontSize::h1), {0, GameConstants::windowX}), GameConstants::windowYPieces[3], FontSize::h1, WHITE);
    DrawText(label_t2, Utils::centralize(MeasureText(label_t2, FontSize::h2), {0, GameConstants::windowX}), GameConstants::windowYPieces[6], FontSize::h2, startColor);
    DrawText(label_t3, Utils::centralize(MeasureText(label_t3, FontSize::note), {0, GameConstants::windowX}), GameConstants::windowYPieces[9], FontSize::note, WHITE);
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
            game.mainTitleScreen(counter % 2 == 0 ? WHITE : BLACK);
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
