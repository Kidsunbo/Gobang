//
// Created by bxs863 on 31/07/2019.
//

#ifndef GOBANG_SCENE_H
#define GOBANG_SCENE_H

#define SFML_STATIC

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Scene {

public:
    virtual int run(sf::RenderWindow& window) = 0;

};


#endif //GOBANG_SCENE_H
