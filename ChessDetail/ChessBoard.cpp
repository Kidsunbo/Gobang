//
// Created by bxs863 on 02/08/2019.
//

#include "ChessBoard.h"

void ChessBoard::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background,states);
    target.draw(text,states);
    for(auto& line : lines) target.draw(line,states);
    for(auto& circle:circles) target.draw(circle,states);
}

ChessBoard::ChessBoard(sf::RenderWindow& window):height(window.getSize().y*0.8f) {


    background.setSize(sf::Vector2f(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)));
    bgTexure.loadFromFile("Resource/img/BackGroundTexure.jpg");
    background.setTexture(&bgTexure);

    font.loadFromFile("Resource/Font/PlayfairDisplay-Bold.ttf");
    text.setString("Your Turn");
    text.setCharacterSize(24);
    text.setFont(font);
    text.setPosition((window.getSize().x-text.getLocalBounds().width)/2.0f,window.getSize().y*0.05f);
    text.setFillColor(sf::Color::Black);

    //Top
    sf::RectangleShape temp;
    temp.setSize(sf::Vector2f(window.getSize().y*0.8f,3));
    temp.setPosition((window.getSize().x-temp.getSize().x)/2.0f,window.getSize().y*0.15f);
    temp.setFillColor(sf::Color::Black);
    lines.push_back(temp);

    //Left
    temp.setSize(sf::Vector2f(3,window.getSize().y*0.8f));
    temp.setPosition((window.getSize().x-window.getSize().y*0.8f-temp.getSize().x)/2.0f,window.getSize().y*0.15f);
    temp.setFillColor(sf::Color::Black);
    lines.push_back(temp);

    //Bottom
    temp.setSize(sf::Vector2f(window.getSize().y*0.8f,3));
    temp.setPosition((window.getSize().x-temp.getSize().x)/2.0f,window.getSize().y*0.95f-temp.getSize().y);
    temp.setFillColor(sf::Color::Black);
    lines.push_back(temp);

    //Right
    temp.setSize(sf::Vector2f(3,window.getSize().y*0.8f));
    temp.setPosition(window.getSize().x-(window.getSize().x-window.getSize().y*0.8f)/2.0f,window.getSize().y*0.15f);
    temp.setFillColor(sf::Color::Black);
    lines.push_back(temp);

    stepLength = window.getSize().y*0.8f/14.0f;
    temp.setSize(sf::Vector2f(window.getSize().y*0.8f,1));
    for(int i =1;i<14;i++){
        temp.setPosition((window.getSize().x-window.getSize().y*0.8f)/2.0f,window.getSize().y*0.15f+static_cast<float>(i)*stepLength);
        lines.push_back(temp);
    }

    temp.setSize(sf::Vector2f(1,window.getSize().y*0.8f));
    for(int i =1;i<14;i++){
        temp.setPosition((window.getSize().x-window.getSize().y*0.8f)/2.0f+ static_cast<float>(i)*stepLength,window.getSize().y*0.15f);
        lines.push_back(temp);
    }

    sf::CircleShape circleShape;
    circleShape.setRadius(3);
    circleShape.setFillColor(sf::Color::Black);
    circleShape.setOrigin(2.5f,2.5f);
    circleShape.setPosition((window.getSize().x-window.getSize().y*0.8f)/2.0f+ 3*stepLength,window.getSize().y*0.15f+3*stepLength);
    circles.push_back(circleShape);
    circleShape.setPosition((window.getSize().x-window.getSize().y*0.8f)/2.0f+ 3*stepLength,window.getSize().y*0.15f+11*stepLength);
    circles.push_back(circleShape);
    circleShape.setPosition((window.getSize().x-window.getSize().y*0.8f)/2.0f+ 11*stepLength,window.getSize().y*0.15f+3*stepLength);
    circles.push_back(circleShape);
    circleShape.setPosition((window.getSize().x-window.getSize().y*0.8f)/2.0f+ 11*stepLength,window.getSize().y*0.15f+11*stepLength);
    circles.push_back(circleShape);


}

sf::Text &ChessBoard::getText() {
    return text;
}

float ChessBoard::getChessBoardWidth() {
    return height;
}

float ChessBoard::getStepLength() const {
    return stepLength;
}
