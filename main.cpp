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
    
    Game(Resources& resources);
    static void Initialize();
    
    void mainTitleScreen(Color startColor);
    void selectionScreen();
    void playingScreen();
    
    struct MainTitleScreenData {
        static constexpr const char* label_t1 = "(Des)Equilibrados!";
        static constexpr const char* label_t2 = "Pressione Enter para começar!";
        static constexpr const char* label_t3 = "IFCE Itapipoca";
    };
    
    struct SelectionScreenData {
        static constexpr const char* label_t1 = "Selecione a dificuldade:";
        static const vector<const char*> labels;
        
        static vector<Button> buttons;
        
        static vector<Button> generateButtons();
    };    
    
    struct PLayingScreenData {
        static constexpr const char* label_t1 = "Para qual lado a equação tenderá?";
    };
};

vector<Button> Game::SelectionScreenData::buttons = Game::SelectionScreenData::generateButtons();

void Game::Initialize() {
    Game::SelectionScreenData::buttons = Game::SelectionScreenData::generateButtons();
}

Game::Game(Resources& resources) {
    Initialize();
}

const vector<const char*> Game::SelectionScreenData::labels = {
    "Fácil",
    "Médio",
    "Difícil",
    "Créditos"
};

vector<Button> Game::SelectionScreenData::generateButtons() {
    vector<Button> v = {};
    for (unsigned int i = 0; i < labels.size(); ++i) {
        v.push_back({5.f, {20, 15}, FontSize::h2, labels[i], WHITE, BLACK, GRAY});
        v[i].update({Utils::centralize(v[i].get_width(), {0, GameConstants::windowX}), GameConstants::windowYPieces[i * 2 + 1]});
    }
    return v;
}

void Game::mainTitleScreen(Color startColor) {
    DrawText(Game::MainTitleScreenData::label_t1, Utils::centralize(MeasureText(Game::MainTitleScreenData::label_t1, FontSize::h1), {0, GameConstants::windowX}), GameConstants::windowYPieces[3], FontSize::h1, WHITE);
    DrawText(Game::MainTitleScreenData::label_t2, Utils::centralize(MeasureText(Game::MainTitleScreenData::label_t2, FontSize::h2), {0, GameConstants::windowX}), GameConstants::windowYPieces[6], FontSize::h2, startColor);
    DrawText(Game::MainTitleScreenData::label_t3, Utils::centralize(MeasureText(Game::MainTitleScreenData::label_t3, FontSize::note), {0, GameConstants::windowX}), GameConstants::windowYPieces[9], FontSize::note, WHITE);
}

void Game::selectionScreen() {
    DrawText(Game::SelectionScreenData::label_t1, Utils::centralize(MeasureText(Game::SelectionScreenData::label_t1, FontSize::h2), {0, GameConstants::windowX}), GameConstants::windowYPieces[0], FontSize::h2, WHITE);
    for (Button button: Game::SelectionScreenData::buttons) {
        button.draw();
    }
}

void Game::playingScreen() {
    DrawText(Game::PlayingScreenData::label_t1, Utils::centralize(MeasureText(Game::PLayingScreenData::label_t1, FontSize::h2), {0, GameConstants::windowX}), GameConstants::windowYPieces[10], FontSize::body, WHITE);
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
            
    while (!WindowShouldClose()) {
        
        BeginDrawing();
        
        ClearBackground(BLACK);
        
        if (game.currentState == GameState::MainTitleScreen) {
            bool changeColor = Utils::timer(GetTime(), start, GameConstants::blinkIterval);
            if (changeColor) ++counter;
            game.mainTitleScreen(counter % 2 == 0 ? WHITE : BLACK);
            if (IsKeyPressed(KEY_ENTER)) {
                game.currentState = GameState::SelectionScreen;
            }
        }
        else if (game.currentState == GameState::SelectionScreen) {
            game.selectionScreen();
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
                
        EndDrawing();
    }
    
    CloseWindow();
    delete resources;
    
    return 0;
}
