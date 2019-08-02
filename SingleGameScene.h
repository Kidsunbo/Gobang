//
// Created by bxs863 on 31/07/2019.
//

#ifndef GOBANG_SINGLEGAMESCENE_H
#define GOBANG_SINGLEGAMESCENE_H

#include "Scene.h"
#include <vector>
#include "ChessDetail/Piece.h"
class SingleGameScene:public Scene {

    std::vector<Piece> pieces;
    bool isMyTurn = true;
    std::vector<std::vector<int>> game = std::vector<std::vector<int>>(15,std::vector<int>(15,-1));

public:

    int run(sf::RenderWindow &window) override;

};


#endif //GOBANG_SINGLEGAMESCENE_H
