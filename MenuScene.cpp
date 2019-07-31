//
// Created by bxs863 on 31/07/2019.
//

#include "MenuScene.h"

int MenuScene::run(sf::RenderWindow& window) {
    // Font
    font.loadFromFile("Resource/Font/PlayfairDisplay-Black.ttf");
    // Text
    title.setFont(font);
    title.setString("Hello");
    title.setCharacterSize(50);
    title.setPosition(window.getSize().x*0.5-title.getLocalBounds().width/2,window.getSize().y*0.1);





    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type ==sf::Event::Closed){return -1;}
        }

        window.clear();
        window.draw(title);
        window.display();
    }
    return -1;
}
