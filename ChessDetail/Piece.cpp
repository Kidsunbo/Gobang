//
// Created by bxs863 on 02/08/2019.
//
#define SFML_STATIC
#include "Piece.h"

void Piece::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(piece,states);
}

Piece::Piece(sf::RenderWindow &window,sf::Texture& texture,int x,int y) {
    piece.setRadius(window.getSize().y/100.0f);
    piece.setOrigin(window.getSize().y/100.0f,window.getSize().y/100.0f);
    piece.setTexture(&texture);

    auto stepLength = window.getSize().y*0.8f/14.0f;
    auto startX = (window.getSize().x-window.getSize().y*0.8f)/2.0f;
    auto startY = window.getSize().y*0.15f;

    piece.setPosition(startX+x*stepLength,startY+y*stepLength);

}

Piece::Piece(sf::RenderWindow &window, sf::Color color, int x, int y) {
    piece.setRadius(getPieceRadius(window));
    piece.setOrigin(getPieceRadius(window),getPieceRadius(window));
    piece.setFillColor(color);
    auto stepLength = window.getSize().y*0.8f/14.0f;
    auto startX = (window.getSize().x-window.getSize().y*0.8f)/2.0f;
    auto startY = window.getSize().y*0.15f;

    piece.setPosition(startX+x*stepLength,startY+y*stepLength);
}


float Piece::getPieceRadius(sf::RenderWindow& window) {
    return window.getSize().y/40.0f;
}


