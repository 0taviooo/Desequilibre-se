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
    vector <Color> colors = {};
    vector <Rectangle> BARS = {};
    
    Bar( 
        Vector2 pos_ = {0, 0},
        float width_ = 0.f,
        float height_ = 0.f,
        int length_ = 0,
        vector <Color> colors_ = {}
    ): pos(pos_), width(width_), length(length_), colors(colors_) {}
    
    
    void construct() {
        for (int i = 0; i < length; ++i) {
            BARS.push_back({pos.x + i * width/length, pos.y, width/length, height});
        }
    }
    void draw(int quantity = 0) {
        for (int i = 0; i < (int) BARS.size(); ++i) {
            if (i >= length - quantity) DrawRectangleRec(BARS[BARS.size() - i], colors[0]);
            else { DrawRectangleRec(BARS[BARS.size() - i], colors[1]); }
        }
    }
};

#endif
