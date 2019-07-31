//
// Created by bxs863 on 31/07/2019.
//

#ifndef GOBANG_SINGLEGAMESCENE_H
#define GOBANG_SINGLEGAMESCENE_H

#include "Scene.h"
class SingleGameScene:public Scene {
public:
    int run(sf::RenderWindow &window) override;

};


#endif //GOBANG_SINGLEGAMESCENE_H
