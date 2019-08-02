//
// Created by bxs863 on 02/08/2019.
//

#include "CheckBoard.h"

void CheckBoard::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}

CheckBoard::CheckBoard(sf::RenderWindow& window) {
    background.setSize(sf::Vector2f(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)));
    bgTexure.loadFromFile("Resource/img/BackGroundTexure.jpg");
    background.setTexture(&bgTexure);

    font.loadFromFile("Resource/Font/Amazing Kids.ttf");
    text.setString("You");
}
