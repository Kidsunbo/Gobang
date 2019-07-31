//
// Created by bxs863 on 31/07/2019.
//

#ifndef GOBANG_MENUSCENE_H
#define GOBANG_MENUSCENE_H

#include "Scene.h"

class MenuScene : public Scene{
private:
    sf::Font font;
    sf::Text title;
    sf::Text subtitle;

    sf::Texture buttonTexture;
    sf::RectangleShape buttonShape;





public:


    int run(sf::RenderWindow& window) override;

};


#endif //GOBANG_MENUSCENE_H
