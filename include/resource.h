#ifndef RESOURCE_H

#define RESOURCE_H

#include <unordered_map>
#include <iostream>

using Images = std::unordered_map<std::string, Texture2D>;
using Musics = std::unordered_map<std::string, Music>;

struct Resources {
    
    Musics musics;
    Images textures;
    
    void loadMusics() {
        musics = {
            //{"[]", LoadMusicStream("../sfx/[].mp3")},
        };
    }
    
    void loadTextures2D() {
        textures = {
            {"b1_0", LoadTexture("gfx/b1_0.png")},
            {"b1_1", LoadTexture("gfx/b1_1.png")},
            {"g1_default", LoadTexture("gfx/g1_default.png")},
            {"g1_0", LoadTexture("gfx/g1_0.png")},
            {"g1_1", LoadTexture("gfx/g1_1.png")}
        };
    }
    Resources() {
        loadMusics();
        loadTextures2D();
    }
    ~Resources() {
        for (auto& [key, music]: musics) {
            UnloadMusicStream(music);
        }
        for (auto& [key, texture]: textures) {
            UnloadTexture(texture);
        }
    }
};

#endif
