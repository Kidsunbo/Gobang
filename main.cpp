#include <vector>
#include <memory>

#include <iostream>

#include "Scene.h"
#include "MenuScene.h"
#include "SingleGameScene.h"
#include "DoubleGameScene.h"
#include "EndScene.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode{sf::VideoMode::getDesktopMode().width/2,sf::VideoMode::getDesktopMode().height/2}, "Gobang");

    std::vector<std::shared_ptr<Scene>> scenes;

    //0: menu 1:single 2:double 3:end
    scenes.emplace_back(std::make_shared<MenuScene>());
    scenes.emplace_back(std::make_shared<SingleGameScene>());
    scenes.emplace_back(std::make_shared<DoubleGameScene>());
    scenes.emplace_back(std::make_shared<EndScene>());
    int scene = 0;

    while(scene>=0){
        scene = scenes[scene]->run(window);
    }


    return 0;
}