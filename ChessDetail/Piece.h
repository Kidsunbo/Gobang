//
// Created by bxs863 on 02/08/2019.
//

#ifndef GOBANG_PIECE_H
#define GOBANG_PIECE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Piece:public sf::Drawable {
    sf::CircleShape piece;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    Piece(sf::RenderWindow& window,sf::Texture& texture,int x,int y);
    Piece(sf::RenderWindow& window,sf::Color color,int x,int y);
    static float getPieceRadius(sf::RenderWindow& window);

};


#endif //GOBANG_PIECE_H
