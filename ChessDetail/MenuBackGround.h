//
// Created by bxs863 on 31/07/2019.
//

#ifndef GOBANG_MENUBACKGROUND_H
#define GOBANG_MENUBACKGROUND_H


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

class MenuBackGround: public sf::Drawable {

private:
    sf::RectangleShape background;
    sf::Texture bgTexure;

    sf::RectangleShape button1;
public:
    const sf::RectangleShape &getButton1() const;

    const sf::RectangleShape &getButton2() const;

private:
    sf::RectangleShape button2;
    sf::Texture btnTexure;

    sf::Text text1;
public:
    sf::Text &getText1();

    sf::Text &getText2();

private:
    sf::Text text2;
    sf::Text title;

    sf::Font font;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    explicit MenuBackGround(sf::RenderWindow& window);

};


#endif //GOBANG_MENUBACKGROUND_H
