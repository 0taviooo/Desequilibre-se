#ifndef RESOURCE_H

#define RESOURCE_H

#include "raylib.h"
#include <unordered_map>
#include <iostream>

using Images = std::unordered_map<std::string, Texture2D>;
using Musics = std::unordered_map<std::string, Music>;
using Sounds = std::unordered_map<std::string, Sound>;

struct Resources {
    
    Musics musics;
    Images textures;
    Sounds sounds;
    
    void loadMusics() {
        musics = {
            {"main_title_music", LoadMusicStream("sfx/main_title_music.mp3")},
            {"menu_music", LoadMusicStream("sfx/menu_music.mp3")},
            {"playing_music", LoadMusicStream("sfx/playing_music.mp3")},
            {"game_over_music", LoadMusicStream("sfx/game_over_music.mp3")}
        };
    }
    void loadSounds() {
        sounds = {
            {"select_sound", LoadSound("sfx/select_sound.mp3")},
            {"click_sound", LoadSound("sfx/click_sound.mp3")}
        };
    }
    void loadTextures2D() {
        textures = {
            {"b1_0", LoadTexture("gfx/b1_0.png")},
            {"b1_1", LoadTexture("gfx/b1_1.png")},
            {"b2_0", LoadTexture("gfx/b2_0.png")},
            {"g1_default", LoadTexture("gfx/g1_default.png")},
            {"g1_0", LoadTexture("gfx/g1_0.png")},
            {"g1_1", LoadTexture("gfx/g1_1.png")}
        };
    }
    Resources() {
        loadMusics();
        loadSounds();
        loadTextures2D();
    }
    ~Resources() {
        for (auto& [key, music]: musics) {
            UnloadMusicStream(music);
        }
        for (auto& [key, sound]: sounds) {
            UnloadSound(sound);
        }
        for (auto& [key, texture]: textures) {
            UnloadTexture(texture);
        }
    }
};

#endif
