#ifndef UTILS_H

#define UTILS_H

struct Utils {
    static bool timer(float currentTime, float& lastTime, float interval);
    static float center(const float f1, const float f2);
    static float centralizeText(const char* text, float size, Vector2 posLimX);
};

float Utils::center(const float f1, const float f2) {
    return (f1 - f2)/2.f;
}

bool Utils::timer(float currentTime, float& lastTime, float interval) {
    if (currentTime - lastTime > interval) {
        lastTime = currentTime;
        return true;
    }
    return false;
}

float Utils::centralizeText(const char* text, float size, Vector2 posLimX) {
    int text_size = MeasureText(text, size);
    float box_size = posLimX.y - posLimX.x;
    float gap = (box_size - text_size) / 2;
    float x = box_size - text_size - gap;
    return x;
}

#endif
