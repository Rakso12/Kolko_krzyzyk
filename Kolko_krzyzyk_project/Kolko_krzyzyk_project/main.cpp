#include "End.h"

int main(){
    
    // tworzenie obiektu obiektu do obs�ugi zasob�w
    ResourceMenager resource;

    // rozpocz�cie dzia�ania programu
    Menu* board = new Menu();
    board->drawMenu(&resource);

    return 0;
}
