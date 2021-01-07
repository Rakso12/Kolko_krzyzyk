#include "AiMedium.h"

void AiMedium::moveAiMedium(std::vector<std::vector<Field*>> pola, int size)
{
    Check sprawdz;
    int wsp_y = 0, wsp_x = 0;
    bool tmp = false;

    do {
        wsp_y = rand() % (size - 1);
        wsp_x = rand() % (size - 1);

        if (sprawdz.czyWygrana(pola, size, "X", wsp_x, wsp_y) && pola[wsp_y][wsp_x]->isAvailable() != 0) {
            tmp = true;
        }
        else if (sprawdz.czyWygrana(pola, size, "O", wsp_x, wsp_y) && pola[wsp_y][wsp_x]->isAvailable() != 0) {
            tmp = true;
        }

    } while (pola[wsp_y][wsp_x]->isAvailable() != 0 && tmp == true);

    pola[wsp_y][wsp_x]->setText('O');
    pola[wsp_y][wsp_x]->setAvailable();
}

int AiMedium::getX()
{
    return wsp_x;
}

int AiMedium::getY()
{
    return wsp_y;
}
/*
std::vector<int> AiMedium::minmax(std::vector<std::vector<Field*>> pola, int ile_ruchow, int size)
{
    std::vector<int> best = { -1, -1, -1000 };

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++) {
                int x = cell[0];
                int y = cell[1];
                std::vector<int> score = minmax(pola, (ile_ruchow - 1), size);
                score[0] = x;
                score[1] = y;

                if (score[2] < best[2]) 
                {
                    best = score
                }
            }
        }
    return best;
}

*/
