//
// Created by bxs863 on 31/07/2019.
//

#define SFML_STATIC

#include "MenuBackGround.h"
#include <string>


void MenuBackGround::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background,states);
    target.draw(button1,states);
    target.draw(button2,states);
    target.draw(text1,states);
    target.draw(text2,states);
    target.draw(title,states);
    target.draw(fps,states);
}

MenuBackGround::MenuBackGround(sf::RenderWindow &window) {
    background.setSize(sf::Vector2f(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)));
    bgTexure.loadFromFile("Resource/img/BackGroundTexure.jpg");
    background.setTexture(&bgTexure);

    btnTexure.loadFromFile("Resource/img/btn.png");
    button1.setSize(sf::Vector2f(window.getSize().x/5.0f, window.getSize().y/7.0f));
    button2.setSize(sf::Vector2f(window.getSize().x/5.0f, window.getSize().y/7.0f));
    button1.setPosition(window.getSize().x*0.15f,window.getSize().y*0.8f);
    button2.setPosition(window.getSize().x*0.65f,window.getSize().y*0.8f);
    button1.setTexture(&btnTexure);
    button2.setTexture(&btnTexure);

    font.loadFromFile("Resource/Font/PlayfairDisplay-Black.ttf");

    text1.setString("1 vs PC");
    text2.setString("1 vs 1");
    title.setString("GoMoKu");
    title.setCharacterSize(100);
    text1.setFont(font);
    text2.setFont(font);
    title.setFont(font);
    auto offset_x = (button1.getSize().x-text1.getLocalBounds().width)/2.0f;
    auto offset_y = (button1.getSize().y-text1.getLocalBounds().height)/2.0f;
    auto offset_x_2 = (button2.getSize().x-text2.getLocalBounds().width)/2.0f;
    auto offset_y_2 = (button2.getSize().y-text2.getLocalBounds().height)/2.0f;
    text1.setPosition(button1.getPosition().x+offset_x+text1.getLocalBounds().left,button1.getPosition().y+offset_y-text1.getLocalBounds().top);
    text2.setPosition(button2.getPosition().x+offset_x_2+text2.getLocalBounds().left,button2.getPosition().y+offset_y_2-text2.getLocalBounds().top);
    title.setPosition((window.getSize().x-title.getLocalBounds().width)/2.0f,window.getSize().y*0.2f);
    text1.setFillColor(sf::Color::Cyan);
    text2.setFillColor(sf::Color::Cyan);
    title.setFillColor(sf::Color::Black);

    fps.setString(std::to_string(0));
    fps.setPosition(10,10);
    fps.setCharacterSize(20);
    fps.setFont(font);
    fps.setFillColor(sf::Color::Black);



}

const sf::RectangleShape &MenuBackGround::getButton1() const {
    return button1;
}

const sf::RectangleShape &MenuBackGround::getButton2() const {
    return button2;
}

sf::Text &MenuBackGround::getText1() {
    return text1;
}

sf::Text &MenuBackGround::getText2() {
    return text2;
}

sf::Text &MenuBackGround::getFps() {
    return fps;
}
