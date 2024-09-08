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
    vector<int> score = {0, 0, 0};
    vector<int> high_score = {0, 0, 0};
    Texture2D b1_sprite;
    Texture2D b2_sprite;
    Texture2D b3_sprite;
    Texture2D g1_sprite;
    Equation current_equation;
    
    Game(Resources& resources);
    static void Initialize();
    
    void mainTitleScreen(Color startColor);
    void selectionScreen();
    void playingScreen(Resources& resources, bool change, bool toggle, Equation equation, int points);
    void gameOverScreen(int score, Color startColor, int best_points, bool new_record);
    
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
        static constexpr const char* label_t3 = "Novo recorde!";
        static constexpr const char* label_t4 = "Recorde: ";
        static constexpr const char* label_t5 = "Não desista!";
        static constexpr const char* label_t6 = "Pressione Enter para retornar!";
    };
};

Game::Game(Resources& resources) {
    Initialize();
    Game::b1_sprite = resources.textures["b1_0"];
    Game::g1_sprite = resources.textures["g1_default"];
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

void Game::playingScreen(Resources& resources, bool change, bool toggle, Equation equation, int points) {
    DrawText(("Pontuação: " + to_string(points)).c_str(), GameConstants::windowXPieces[1], GameConstants::windowYPieces[1], FontSize::note, WHITE);
    
    DrawText(equation.to_draw_string.c_str(), Utils::centralize(MeasureText(equation.to_draw_string.c_str(), FontSize::h2), {0, GameConstants::windowX}), GameConstants::windowYPieces[3], FontSize::h2, WHITE);
    DrawText(equation.questions[0].text, Utils::centralize(MeasureText(equation.questions[0].text, FontSize::body)/2, {0, GameConstants::windowXPieces[9]}), GameConstants::windowYPieces[4], FontSize::body, WHITE);
    
    DrawText(Game::PlayingScreenData::label_t1, Utils::centralize(MeasureText(Game::PlayingScreenData::label_t1, FontSize::body), {0, GameConstants::windowX}), GameConstants::windowYPieces[9], FontSize::body, WHITE);
    
    Game::b1_sprite = change ? resources.textures["b1_0"] : resources.textures["b1_1"];
    Game::b2_sprite = change ? resources.textures["b1_0"] : resources.textures["b1_1"];
    Game::b3_sprite = change ? resources.textures["b1_0"] : resources.textures["b1_1"];
    Game::g1_sprite = change ? resources.textures["g1_default"] : toggle ? resources.textures["g1_0"] : resources.textures["g1_1"];
    
    DrawTexture(b1_sprite, Utils::centralize(32, {GameConstants::windowXPieces[0], GameConstants::windowXPieces[3]}), GameConstants::windowYPieces[7], WHITE);
    DrawTexture(b2_sprite, Utils::centralize(32, {GameConstants::windowXPieces[5], GameConstants::windowXPieces[11]}), GameConstants::windowYPieces[7], WHITE);
    DrawTexture(b3_sprite, Utils::centralize(32, {0, GameConstants::windowX}), GameConstants::windowYPieces[7], WHITE);
    
    DrawTexture(g1_sprite, Utils::centralize(512, {0, GameConstants::windowX}), GameConstants::windowYPieces[6], WHITE);
    
    Game::PlayingScreenData::button_left.draw();
    Game::PlayingScreenData::button_right.draw();
}

void Game::gameOverScreen(int score, Color startColor, int best_points, bool new_record) {
    DrawText(Game::GameOverScreenData::label_t1, Utils::centralize(MeasureText(Game::GameOverScreenData::label_t1, FontSize::h1), {0, GameConstants::windowX}), GameConstants::windowYPieces[3], FontSize::h1, WHITE);
    
    DrawText((string(Game::GameOverScreenData::label_t2) + to_string(score)).c_str(), Utils::centralize(MeasureText((string(Game::GameOverScreenData::label_t2) + to_string(score)).c_str(), FontSize::body), {0, GameConstants::windowX}), GameConstants::windowYPieces[4], FontSize::body, WHITE);
    
    if (new_record) DrawText(Game::GameOverScreenData::label_t3, Utils::centralize(MeasureText(Game::GameOverScreenData::label_t3, FontSize::body), {0, GameConstants::windowX}), GameConstants::windowYPieces[5], FontSize::body, startColor);
    else {
        DrawText(string((Game::GameOverScreenData::label_t4) + to_string(best_points)).c_str(), Utils::centralize(MeasureText(string((Game::GameOverScreenData::label_t4) + to_string(best_points)).c_str(), FontSize::body), {0, GameConstants::windowX}), GameConstants::windowYPieces[5], FontSize::body, startColor);
    }
    
    DrawText(Game::GameOverScreenData::label_t5, Utils::centralize(MeasureText(Game::GameOverScreenData::label_t5, FontSize::h2), {0, GameConstants::windowX}), GameConstants::windowYPieces[6], FontSize::h2, WHITE);
    DrawText(Game::GameOverScreenData::label_t6, Utils::centralize(MeasureText(Game::GameOverScreenData::label_t6, FontSize::h2), {0, GameConstants::windowX}), GameConstants::windowYPieces[7], FontSize::h2, startColor);
}

int main() {
    InitWindow(GameConstants::windowX, GameConstants::windowY, "(Des)Equilibre-se!");
    
    const int fps = 60;
    SetTargetFPS(fps);
    
    InitAudioDevice();
    Resources* resources = new Resources();
    Game game = {*resources};
    game.current_equation = material_data[Random::gen(0, material_data.size() - 1)];
    
    bool changeColor = false;
    bool toggle = false;
    bool toggle_two = false;
    bool new_record = false;
    
    float start = GetTime();
    int counter = 0;
    
    Bar time_bar;
    
    while (!WindowShouldClose()) {
        
        BeginDrawing();
        
        ClearBackground(BLACK);
        
        if (game.currentState == GameState::MainTitleScreen) {
            changeColor = Utils::timer(GetTime(), start, GameConstants::blinkIterval);
            if (changeColor) {
                ++counter;
                toggle = counter % 2 == 0;
            }
            
            game.mainTitleScreen(toggle ? WHITE : BLACK);
            
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
                ++counter;
                toggle = counter % 2 == 0;
                if (toggle) toggle_two = !toggle_two;
                if (time_bar.update(1)) game.currentState = GameState::GameOverScreen;
            }
            
            if (!game.current_equation.questions[0].answer && Game::PlayingScreenData::button_left.click()) {
                game.score[game.difficulty] += 20;
                game.current_equation = material_data[Random::gen(0, material_data.size() - 1)];
                time_bar.remaining = time_bar.length;
            }
            else if (game.current_equation.questions[0].answer && Game::PlayingScreenData::button_right.click()) {
                game.score[game.difficulty] += 20;
                game.current_equation = material_data[Random::gen(0, material_data.size() - 1)];
                time_bar.remaining = time_bar.length;
            }
            else if (
                (game.current_equation.questions[0].answer && Game::PlayingScreenData::button_left.click()) ||
                (!game.current_equation.questions[0].answer && Game::PlayingScreenData::button_right.click())
            ) {
                game.currentState = GameState::GameOverScreen;
            }
            if (game.currentState == GameState::GameOverScreen) {
                new_record = game.score[game.difficulty] > game.high_score[game.difficulty];
                if (new_record) game.high_score[game.difficulty] = game.score[game.difficulty];
            }
            
            game.playingScreen(*resources, toggle, toggle_two, game.current_equation, game.score[game.difficulty]);
            time_bar.draw();
        }
        else if (game.currentState == GameState::GameOverScreen) {
            changeColor = Utils::timer(GetTime(), start, GameConstants::blinkIterval);
            if (changeColor) {
                ++counter;
                toggle = counter % 2 == 0;
            }
            
            game.gameOverScreen(game.high_score[game.difficulty], toggle ? WHITE : BLACK, game.high_score[game.difficulty], new_record);
            
            if (IsKeyPressed(KEY_ENTER)) {
                game.score[game.difficulty] = 0;
                game.currentState = GameState::SelectionScreen;
            }            
        }
                
        EndDrawing();
    }
    
    CloseWindow();
    delete resources;
    
    return 0;
}
