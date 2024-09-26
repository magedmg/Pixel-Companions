#pragma once
#include "Cat.hpp"

class greyCat : public Cat {
    private:
        Texture2D standTextures[4];
        Texture2D runRightTextures[6];
        Texture2D runLeftTextures[6];
        Image deathImage;
        Texture2D deathTexture;

    public:
        greyCat();
        ~greyCat();
        void Draw();
};