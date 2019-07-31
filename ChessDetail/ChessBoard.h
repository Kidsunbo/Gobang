//
// Created by bxs863 on 31/07/2019.
//

#ifndef GOBANG_CHESSBOARD_H
#define GOBANG_CHESSBOARD_H

#include <SFML/Graphics.hpp>

class ChessBoard:public sf::Drawable {
protected:
    void draw(RenderTarget &target, sf::RenderStates states) const override;

};


#endif //GOBANG_CHESSBOARD_H
