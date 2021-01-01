#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Field.h"
#include "Board.h"
#include "Menu.h"

int main(){
    
    Menu* board = new Menu();
    board->drawMenu();

    return 0;
}
