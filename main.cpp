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
#include "include/question.h"
#include "include/equation.h"
#include "include/bar.h"
#include "include/data.h"

using namespace std;

struct Game {
    GameState currentState = GameState::MainTitleScreen;
    int difficulty = 0;
    int score = 0;
    
    Game(Resources& resources);
    static void Initialize();
    
    void mainTitleScreen(Color startColor);
    void selectionScreen();
    void playingScreen();
    void gameOverScreen(int score, Color startColor);
    
    struct MainTitleScreenData {
        static constexpr const char* label_t1 = "(Des)Equilibre-se!";
        static constexpr const char* label_t2 = "Pressione Enter para começar!";
        static constexpr const char* label_t3 = "IFCE Itapipoca";
    };
    
    struct SelectionScreenData {
        static constexpr const char* label_t1 = "Selecione a dificuldade:";
        static const vector<const char*> labels;
        
        static vector<Button> buttons;
        
        static vector<Button> generateButtons();
    };    
    
    struct PlayingScreenData {
        static constexpr const char* label_t1 = "Para qual lado \na equação tenderá?";
        static constexpr const char* label_t2 = "Esquerda";
        static constexpr const char* label_t3 = "Direita";
        
        static Button button_left;
        static Button button_right;
        
        static void generateButtons();
    };
    
    struct GameOverScreenData {
        static constexpr const char* label_t1 = "Fim de Jogo!";
        static constexpr const char* label_t2 = "Pontuação: ";
        static constexpr const char* label_t3 = "Não desista!";
        static constexpr const char* label_t4 = "Pressione Enter para retornar!";
    };
};

Game::Game(Resources& resources) {
    Initialize();
}

vector<Button> Game::SelectionScreenData::buttons = Game::SelectionScreenData::generateButtons();
void Game::Initialize() {
    Game::SelectionScreenData::buttons = Game::SelectionScreenData::generateButtons();
    Game::PlayingScreenData::generateButtons();
}
const vector<const char*> Game::SelectionScreenData::labels = {
    "Fácil",
    "Médio",
    "Difícil"
};
vector<Button> Game::SelectionScreenData::generateButtons() {
    vector<Button> v = {};
    for (unsigned int i = 0; i < labels.size(); ++i) {
        v.push_back({5.f, {20, 15}, FontSize::h2, labels[i], WHITE, BLACK, GRAY});
        v[i].update({Utils::centralize(v[i].get_width(), {0, GameConstants::windowX}), GameConstants::windowYPieces[i * 2 + 4]});
    }
    return v;
}

Button Game::PlayingScreenData::button_left;
Button Game::PlayingScreenData::button_right;
void Game::PlayingScreenData::generateButtons() {
    button_left = {5.f, {20, 15}, FontSize::h2, label_t2, WHITE, BLACK, GRAY};
    button_right = {5.f, {20, 15}, FontSize::h2, label_t3, WHITE, BLACK, GRAY};
    
    button_left.update({Utils::centralize(button_left.get_width(), {GameConstants::windowXPieces[0], GameConstants::windowXPieces[4]}), GameConstants::windowYPieces[9]});
    button_right.update({Utils::centralize(button_right.get_width(), {GameConstants::windowXPieces[5], GameConstants::windowXPieces[11]}), GameConstants::windowYPieces[9]});
}

void Game::mainTitleScreen(Color startColor) {
    DrawText(Game::MainTitleScreenData::label_t1, Utils::centralize(MeasureText(Game::MainTitleScreenData::label_t1, FontSize::h1), {0, GameConstants::windowX}), GameConstants::windowYPieces[3], FontSize::h1, WHITE);
    DrawText(Game::MainTitleScreenData::label_t2, Utils::centralize(MeasureText(Game::MainTitleScreenData::label_t2, FontSize::h2), {0, GameConstants::windowX}), GameConstants::windowYPieces[6], FontSize::h2, startColor);
    DrawText(Game::MainTitleScreenData::label_t3, Utils::centralize(MeasureText(Game::MainTitleScreenData::label_t3, FontSize::note), {0, GameConstants::windowX}), GameConstants::windowYPieces[9], FontSize::note, WHITE);
}

void Game::selectionScreen() {
    DrawText(Game::SelectionScreenData::label_t1, Utils::centralize(MeasureText(Game::SelectionScreenData::label_t1, FontSize::h2), {0, GameConstants::windowX}), GameConstants::windowYPieces[3], FontSize::h2, WHITE);
    for (Button button: Game::SelectionScreenData::buttons) {
        button.draw();
    }
}

void Game::playingScreen() {
    DrawText(material_data[0].to_draw_string.c_str(), Utils::centralize(MeasureText(material_data[0].to_draw_string.c_str(), FontSize::h2), {0, GameConstants::windowX}), GameConstants::windowYPieces[3], FontSize::h2, WHITE);
    DrawText(material_data[0].questions[0].text, Utils::centralize(MeasureText(material_data[0].questions[0].text, FontSize::body)/2, {0, GameConstants::windowXPieces[9]}), GameConstants::windowYPieces[4], FontSize::body, WHITE);
    
    DrawText(Game::PlayingScreenData::label_t1, Utils::centralize(MeasureText(Game::PlayingScreenData::label_t1, FontSize::body), {0, GameConstants::windowX}), GameConstants::windowYPieces[9], FontSize::body, WHITE);
    DrawRectangle(Utils::centralize(32, {GameConstants::windowXPieces[0], GameConstants::windowXPieces[3]}), GameConstants::windowYPieces[7], 32, 64, BLUE);
    DrawRectangle(Utils::centralize(32, {GameConstants::windowXPieces[5], GameConstants::windowXPieces[11]}), GameConstants::windowYPieces[7], 32, 64, RED);
    DrawRectangle(Utils::centralize(32, {0, GameConstants::windowX}), GameConstants::windowYPieces[7], 32, 64, GREEN);
    DrawRectangle(Utils::centralize(512, {0, GameConstants::windowX}), GameConstants::windowYPieces[6], 512, 32, PURPLE);
    Game::PlayingScreenData::button_left.draw();
    Game::PlayingScreenData::button_right.draw();
}

void Game::gameOverScreen(int score, Color startColor) {
    DrawText(Game::GameOverScreenData::label_t1, Utils::centralize(MeasureText(Game::GameOverScreenData::label_t1, FontSize::h1), {0, GameConstants::windowX}), GameConstants::windowYPieces[3], FontSize::h1, WHITE);
    DrawText((string(Game::GameOverScreenData::label_t2) + to_string(score)).c_str(), Utils::centralize(MeasureText(Game::GameOverScreenData::label_t2, FontSize::body), {0, GameConstants::windowX}), GameConstants::windowYPieces[5], FontSize::body, WHITE);
    DrawText(Game::GameOverScreenData::label_t3, Utils::centralize(MeasureText(Game::GameOverScreenData::label_t3, FontSize::h2), {0, GameConstants::windowX}), GameConstants::windowYPieces[6], FontSize::h2, WHITE);
    DrawText(Game::GameOverScreenData::label_t4, Utils::centralize(MeasureText(Game::GameOverScreenData::label_t4, FontSize::h2), {0, GameConstants::windowX}), GameConstants::windowYPieces[7], FontSize::h2, startColor);
}

int main() {
    InitWindow(GameConstants::windowX, GameConstants::windowY, "(Des)Equilibre-se!");
    
    const int fps = 60;
    SetTargetFPS(fps);
    
    InitAudioDevice();
    Resources* resources = new Resources();
    Game game = {*resources};
    
    bool changeColor;
    
    float start = GetTime();
    int counter = 0;
    
    Bar time_bar;
    
    while (!WindowShouldClose()) {
        
        BeginDrawing();
        
        ClearBackground(BLACK);
        
        if (game.currentState == GameState::MainTitleScreen) {
            changeColor = Utils::timer(GetTime(), start, GameConstants::blinkIterval);
            if (changeColor) ++counter;
            
            game.mainTitleScreen(counter % 2 == 0 ? WHITE : BLACK);
            
            if (IsKeyPressed(KEY_ENTER)) {
                game.currentState = GameState::SelectionScreen;
            }
        }
        else if (game.currentState == GameState::SelectionScreen) {
            game.selectionScreen();
            if (Game::SelectionScreenData::buttons[0].click()) {
                game.difficulty = 0;
                game.currentState = GameState::PlayingScreen;
                time_bar = {{0, 0}, GameConstants::windowX, 32, 15 - game.difficulty * 5, {GREEN, MAROON}};
            }
            else if (Game::SelectionScreenData::buttons[1].click()) {
                game.difficulty = 1;
                game.currentState = GameState::PlayingScreen;
                time_bar = {{0, 0}, GameConstants::windowX, 32, 15 - game.difficulty * 5, {GREEN, MAROON}};
            }
            else if (Game::SelectionScreenData::buttons[2].click()) {
                game.difficulty = 2;
                game.currentState = GameState::PlayingScreen;
                time_bar = {{0, 0}, GameConstants::windowX, 32, 15 - game.difficulty * 5, {GREEN, MAROON}};
            }
        }
        else if (game.currentState == GameState::PlayingScreen) {
            if (Utils::timer(GetTime(), start, 1)) {
                if (time_bar.update(1)) game.currentState = GameState::GameOverScreen;
            }
            game.playingScreen();
            time_bar.draw();
        }
        else if (game.currentState == GameState::GameOverScreen) {
            changeColor = Utils::timer(GetTime(), start, GameConstants::blinkIterval);
            if (changeColor) ++counter;
            
            game.gameOverScreen(game.score, counter % 2 == 0 ? WHITE : BLACK);
            
            if (IsKeyPressed(KEY_ENTER)) {
                game.currentState = GameState::SelectionScreen;
            }            
        }
                
        EndDrawing();
    }
    
    CloseWindow();
    delete resources;
    
    return 0;
}
