//
// Created by bxs863 on 31/07/2019.
//

#include "MenuScene.h"
#include <iostream>
using namespace std;
int MenuScene::run(sf::RenderWindow& window) {

    MenuBackGround chessBoard(window);
    auto btn1_pos = chessBoard.getButton1().getPosition();
    auto btn2_pos = chessBoard.getButton2().getPosition();
    auto btn1_size = chessBoard.getButton1().getSize();
    auto btn2_size = chessBoard.getButton2().getSize();


    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type ==sf::Event::Closed){return -1;}
            auto mouse = sf::Mouse::getPosition(window);
            if(mouse.x>btn1_pos.x&&mouse.x<btn1_pos.x+btn1_size.x && mouse.y>btn1_pos.y && mouse.y<btn1_pos.y+btn1_size.y){
                chessBoard.getText1().setFillColor(sf::Color::Red);
            }
            else chessBoard.getText1().setFillColor(sf::Color::Cyan);
            if(mouse.x>btn2_pos.x&&mouse.x<btn2_pos.x+btn2_size.x && mouse.y>btn2_pos.y && mouse.y<btn2_pos.y+btn2_size.y){
                chessBoard.getText2().setFillColor(sf::Color::Red);
            }
            else chessBoard.getText2().setFillColor(sf::Color::Cyan);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(mouse.x>btn1_pos.x&&mouse.x<btn1_pos.x+btn1_size.x && mouse.y>btn1_pos.y && mouse.y<btn1_pos.y+btn1_size.y){
                    return 1;
                }
                if(mouse.x>btn2_pos.x&&mouse.x<btn2_pos.x+btn2_size.x && mouse.y>btn2_pos.y && mouse.y<btn2_pos.y+btn2_size.y){
                    return 2;
                }
            }
        }

        window.clear();
        window.draw(chessBoard);
        window.display();
    }
    return -1;
}
