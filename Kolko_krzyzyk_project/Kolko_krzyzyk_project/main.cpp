#include "ResourceMenager.h"
#include "Menu.h"

int main(){
    
    // tworzenie obiektu obiektu do obs³ugi zasobów
    ResourceMenager resource;

    // rozpoczêcie dzia³ania programu
    Menu* board = new Menu();
    board->drawMenu(&resource);

    return 0;
}
