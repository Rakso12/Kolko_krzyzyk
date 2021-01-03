#include "AiLow.h"

void AiLow::moveAiLow(std::vector<std::vector<Field*>> pola, int size)
{
    int wsp_y = 0, wsp_x = 0;
    
    do{
        wsp_y = rand() % (size - 1);
        wsp_x = rand() % (size - 1);
    } while (pola[wsp_y][wsp_x]->isAvailable() != 0);
    
    pola[wsp_y][wsp_x]->setText('O');
    pola[wsp_y][wsp_x]->setAvailable();
}
