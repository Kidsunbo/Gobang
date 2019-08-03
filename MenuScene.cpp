//
// Created by bxs863 on 31/07/2019.
//

#include "MenuScene.h"
#include <iostream>
#include <string>

using namespace std;
int MenuScene::run(sf::RenderWindow& window) {

    MenuBackGround menuBackGround(window);
    auto btn1_pos = menuBackGround.getButton1().getPosition();
    auto btn2_pos = menuBackGround.getButton2().getPosition();
    auto btn1_size = menuBackGround.getButton1().getSize();
    auto btn2_size = menuBackGround.getButton2().getSize();

    sf::Clock clock;
    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type ==sf::Event::Closed){return -1;}
            auto mouse = sf::Mouse::getPosition(window);
            if(mouse.x>btn1_pos.x&&mouse.x<btn1_pos.x+btn1_size.x && mouse.y>btn1_pos.y && mouse.y<btn1_pos.y+btn1_size.y){
                menuBackGround.getText1().setFillColor(sf::Color::Red);
            }
            else menuBackGround.getText1().setFillColor(sf::Color::Cyan);
            if(mouse.x>btn2_pos.x&&mouse.x<btn2_pos.x+btn2_size.x && mouse.y>btn2_pos.y && mouse.y<btn2_pos.y+btn2_size.y){
                menuBackGround.getText2().setFillColor(sf::Color::Red);
            }
            else menuBackGround.getText2().setFillColor(sf::Color::Cyan);
            if(event.type==sf::Event::MouseButtonReleased){
                if(mouse.x>btn1_pos.x&&mouse.x<btn1_pos.x+btn1_size.x && mouse.y>btn1_pos.y && mouse.y<btn1_pos.y+btn1_size.y){
                    return 1;
                }
                if(mouse.x>btn2_pos.x&&mouse.x<btn2_pos.x+btn2_size.x && mouse.y>btn2_pos.y && mouse.y<btn2_pos.y+btn2_size.y){
                    return 2;
                }
            }
        }

        menuBackGround.getFps().setString(std::to_string(static_cast<int >(1/clock.restart().asSeconds())));


        window.clear();
        window.draw(menuBackGround);
        window.display();
    }
    return -1;
}
