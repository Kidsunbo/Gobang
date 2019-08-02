//
// Created by bxs863 on 02/08/2019.
//

#ifndef GOBANG_CHESSBOARD_H
#define GOBANG_CHESSBOARD_H

#define SFML_STATIC

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

class ChessBoard: public sf::Drawable{

    float height = 0;
    float stepLength = 0;
public:
    float getStepLength() const;

private:
    sf::RectangleShape background;
    sf::Texture bgTexure;

    sf::Text text;
public:
    sf::Text &getText();

private:
    sf::Font font;

    std::vector<sf::RectangleShape> lines;
    std::vector<sf::CircleShape> circles;
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    ChessBoard(sf::RenderWindow& window);

    float getChessBoardWidth();
};


#endif //GOBANG_CHESSBOARD_H
