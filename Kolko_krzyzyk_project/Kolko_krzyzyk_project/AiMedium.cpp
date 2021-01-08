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

sf::Vector2i AiMedium::findBestMove(std::vector<std::vector<Field*>> pola, int size, int wsp_x, int wsp_y, Check* check, char znak)
{
    int bestVal = - 1000;
    sf::Vector2i bestMove;
    bestMove.x = -1;
    bestMove.y = -1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            if (pola[i][j]->isAvailable() != 0) {
                pola[i][j]->setText(znak);

                int moveVal = minMax(pola, 0, false, size, check);

                pola[i][j]->setText('_');

                if (moveVal > bestVal) {
                    bestMove.x = i;
                    bestMove.y = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

int AiMedium::minMax(std::vector<std::vector<Field*>> pola, int depth, bool isMax, int size, Check* check)
{
    int score = check->czyWygrana(pola, size, "X", wsp_x, wsp_y);
    if (score == 1) {
        return 1;
    }
    if (isMovesLeft(pola, size) == false) {
        return 0;
    }

    if (isMax) {
        int best = - 1000;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 3; j++) {
                if (pola[i][j]->isAvailable() != 0) {
                    pola[i][j]->setText('O');

                    best = std::max(best, minMax(pola, (depth + 1), !isMax, size, check));

                    pola[i][j]->setText('_');
                }
            }
        }
        return best;
    }
    else {
        int best = 1000;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 3; j++) {
                if (pola[i][j]->isAvailable() != 0) {
                    pola[i][j]->setText('X');

                    best = std::min(best, minMax(pola, (depth + 1), !isMax, size, check));

                    pola[i][j]->setText('_');
                }
            }
        }
        return best;
    }
}



bool AiMedium::isMovesLeft(std::vector<std::vector<Field*>> pola, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (pola[i][j]->isAvailable() != 0) {
                return true;
            }
        }
    }
    return false;
}
