#include "End.h"

int main(){
    ResourceMenager resource; // Obiekt obs�ugi zasob�w sfml'a

    Menu* board = new Menu();
    board->drawMenu(&resource); // Rozpocz�cie dzia�ania programu

    return 0;
}
