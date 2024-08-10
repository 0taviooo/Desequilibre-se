#include <iostream>
#include <raylib.h>
#include <vector>
#include <ctime>
#include <cmath>
#include <string>
#include <unordered_map>

#include "include/constants.h"

using namespace std;

int main() {
    InitWindow(Constants::windowX, Constants::windowY, "Química");
    const int fps = 60;
    SetTargetFPS(fps);
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        
        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}
