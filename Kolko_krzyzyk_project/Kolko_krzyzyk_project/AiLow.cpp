#include "AiLow.h"

/// <summary>
/// 
/// </summary>
/// <param name="pola"> obiekt planszy </param>
/// <param name="size"> rozmiar planszy </param>
void AiLow::moveAiLow(std::vector<std::vector<Field*>> pola, int size)
{
    do{
        this->wsp_y = rand() % (size - 1);
        this->wsp_x = rand() % (size - 1);
    } while (pola[wsp_y][wsp_x]->isAvailable() != 0);
    
    pola[wsp_y][wsp_x]->setText('O');
    pola[wsp_y][wsp_x]->setAvailable();
}

int AiLow::getY()
{
    return wsp_y;
}

int AiLow::getX()
{
    return wsp_x;
}
