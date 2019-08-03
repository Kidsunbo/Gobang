//
// Created by bxs863 on 31/07/2019.
//
#include "SingleGameScene.h"
#include "ChessDetail/ChessBoard.h"

#include <mutex>
#include <thread>

int SingleGameScene::run(sf::RenderWindow &window) {
    ChessBoard chessBoard{window};
    std::mutex mutex;

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                return -1;
            }
            if(event.type==sf::Event::MouseButtonReleased && isMyTurn){
                auto mouse_x = event.mouseButton.x;
                auto mouse_y = event.mouseButton.y;
                mouse_x-= (window.getSize().x - chessBoard.getChessBoardWidth()) / 2.0f;
                mouse_y-=(window.getSize().y*0.15f);
                int b_x = static_cast<int>((mouse_x+chessBoard.getStepLength()/2) / chessBoard.getStepLength());
                int b_y = static_cast<int>((mouse_y+chessBoard.getStepLength()/2) / chessBoard.getStepLength());
                if(b_x>=0&&b_y>=0&&b_x<15&&b_y<15&&game.at(b_x).at(b_y)==-1) {
                    pieces.emplace_back(window, sf::Color::Black, b_x, b_y);
                    isMyTurn = false;
                }
                std::thread t([&](){
                    //get the x and y
                    int x = 0;
                    int y = 0;
                    mutex.lock();
                    pieces.emplace_back(window,sf::Color::White,x,y);
                    mutex.unlock();
                    isMyTurn = true;
                });
                t.detach();
            }
        }

        if(isMyTurn) chessBoard.getText().setString("Your Turn");
        else chessBoard.getText().setString("PC's Turn");

        window.clear();
        window.draw(chessBoard);
        mutex.lock();
        for(auto& piece : pieces) window.draw(piece);
        mutex.unlock();
        window.display();

    }
    return -1;
}

