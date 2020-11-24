#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Field.h"
#include "Board.h"

int main(){
    
    Board* board = new Board();
    board->DrawBoard();

    return 0;
}