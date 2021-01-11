#include "End.h"

int main(){
    ResourceMenager resource; // Obiekt obs³ugi zasobów sfml'a

    Menu* board = new Menu();
    board->drawMenu(&resource); // Rozpoczêcie dzia³ania programu

    return 0;
}
