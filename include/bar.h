#ifndef BAR_H

#define BAR_H

#include <vector>
#include "raylib.h"

using namespace std;

struct Bar {
    Vector2 pos = {0, 0};
    float width = 0.f;
    float height = 0.f;
    int length = 0;
    int remaining = 0;
    vector <Color> colors = {};
    vector <Rectangle> BARS = {};
    
    Bar( 
        Vector2 pos_ = {0, 0},
        float width_ = 0.f,
        float height_ = 0.f,
        int length_ = 0,
        vector <Color> colors_ = {}
    ): pos(pos_), width(width_), height(height_), length(length_), colors(colors_) {
        construct();
    }
    
    void construct() {
        for (int i = 0; i < length; ++i) {
            BARS.push_back({pos.x + i * width/length, pos.y, width/length, height});
        }
        remaining = length;
    }
    bool update(int quantity = 0) {
        remaining -= quantity;
        return remaining <= 0;
    }
    void draw() {
        for (int i = 0; i < (int) BARS.size(); ++i) {
            if (i < remaining) DrawRectangleRec(BARS[i], colors[0]);
            else { DrawRectangleRec(BARS[i], colors[1]); }
        }
    }
};

#endif
