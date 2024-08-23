#ifndef BUTTON_H

#define BUTTON_H

#include "raylib.h"
#include "utils.h"

struct Button {
    Vector2 pos = {0, 0};
    Vector2 gap = {0, 0};
    float border = 0.f;
    float size = 0.f;
    string content = "";
    Color color1 = BLANK;
    Color color2 = BLANK;
    Color color3 = BLANK
    Rectangle BUTTON = {pos.x, pos.y, 0, 0};

    Button(
        float border_ = 0.f,
        float gap_ = 0.f,
        float size = 0.f;
        Color color1_ = BLANK,
        Color color2_ = BLANK,
        Color color3_ = BLANK
    ):
    border(border_), gap(gap_), size(size_), color1(color1_), color2(color2_), color3(color3_) {
        float width = get_width();
        float height = get_height();
        BUTTON = {pos.x + border, pos.y + border, width, height};
    }
    
    float get_width(bool border_on = true) {
        float boder_num = border_on ? border : 0;
        float width = MeasureText(content.c_str(), size) + (border_num + gap.x) * 2;
        return width;
    }
    float get_height(bool border_on = true) {
        float boder_num = border_on ? border : 0;
        float height = size + (border_num + gap.y) * 2;
        return height;
    }
    void draw(Color coloration = BLANK) {
        const char text_content = content.c_str();
        int content_size = MeasureText(text_content, size);
        DrawRectangle(pos.x, pos.y, get_width(), get_height(), color1);
        DrawRectangleRec(BUTTON, color2);
        DrawText(text_content, pos.x + border + (get_width(false) - content_size) / 2, pos.y + border + (get_height(false) - size) / 2, size, color3);
    }
    bool click() {
        return (CheckCollisionPointRec(GetMousePosition(), BUTTON) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT));
    }
};

#endif
