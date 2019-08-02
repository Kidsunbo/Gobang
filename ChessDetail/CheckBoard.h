//
// Created by bxs863 on 02/08/2019.
//

#ifndef GOBANG_CHECKBOARD_H
#define GOBANG_CHECKBOARD_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

class CheckBoard:public sf::Drawable{


    sf::RectangleShape background;
    sf::Texture bgTexure;

    sf::Text text;
    sf::Font font;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    CheckBoard(sf::RenderWindow& window);
};


#endif //GOBANG_CHECKBOARD_H
