#include "AiMedium.h"

/// <summary>
/// Funkcja uruchamiaj¹ca minmax 
/// </summary>
/// <param name="pola"> obiekt planszy </param>
/// <param name="size"> rozmiar planszy </param>
void AiMedium::moveAiMedium(std::vector<std::vector<Field*>> pola, int size)
{
    Check sprawdz;
    sf::Vector2i best;
    best = findBestMove(pola, size, &sprawdz, 'O');

    pola[best.y][best.x]->setText('O');
    pola[best.y][best.x]->setAvailable();
}

int AiMedium::getY()
{
    return wsp_y;
}

int AiMedium::getX()
{
    return wsp_x;
}

/// <summary>
/// Funkcja szukania najlepszego ruchu w danym momencie
/// </summary>
/// <param name="pola"> obiekt planszy </param>
/// <param name="size"> rozmiar planszy </param>
/// <param name="check"> obiekt sprawdzania wygranej </param>
/// <param name="znak"> znak aktualnego gracza </param>
/// <returns></returns>
sf::Vector2i AiMedium::findBestMove(std::vector<std::vector<Field*>> pola, int size, Check* check, char znak)
{
    int bestVal = - 1000;
    sf::Vector2i bestMove;
    bestMove.x = -1;
    bestMove.y = -1;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (pola[i][j]->isAvailable() == 0) {
                
                pola[i][j]->setText(znak);
                int moveVal = minMax(pola, 0, false, size, check, i, j);
                pola[i][j]->setText('_');

                if (moveVal > bestVal) 
                {
                    bestMove.x = i;
                    bestMove.y = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

/// <summary>
/// Funkcja minmaxowa
/// </summary>
/// <param name="pola"> obiekt planszy </param>
/// <param name="depth"> licznik wêz³a zagnie¿d¿enia</param>
/// <param name="isMax"> znacznik zawodnika </param>
/// <param name="size"> rozmiar planszy </param>
/// <param name="check"> obiekt sprawdzaj¹cy</param>
/// <param name="wsp_x"> wspó³rzêdna x wykonywanego ruchu </param>
/// <param name="wsp_y"> wspó³rzêdna y wykonywanego ruchu </param>
/// <returns></returns>
int AiMedium::minMax(std::vector<std::vector<Field*>> pola, int depth, bool isMax, int size, Check* check, int wsp_x, int wsp_y)
{
    int score = check->czyWygrana(pola, size, "0", wsp_x, wsp_y);

    if (score == 1) return 1;

    if (isMovesLeft(pola, size) == false) return 0;

    if (isMax) {
        int best = - 1000;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 3; j++) {
                if (pola[i][j]->isAvailable() == 0) 
                {
                    pola[i][j]->setText('O');
                    best = std::max(best, minMax(pola, (depth + 1), !isMax, size, check, i, j));
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
                if (pola[i][j]->isAvailable() == 0) 
                {
                    pola[i][j]->setText('X');
                    best = std::min(best, minMax(pola, (depth + 1), !isMax, size, check, i, j));
                    pola[i][j]->setText('_');
                }
            }
        }
        return best;
    }
}


/// <summary>
/// Funkcja sprawdzaj¹ca czy pozosta³y jakiekolwiek ruchy do wykonania na planszy
/// </summary>
/// <param name="pola"> obiekt planszy </param>
/// <param name="size"> rozmiar </param>
/// <returns></returns>
bool AiMedium::isMovesLeft(std::vector<std::vector<Field*>> pola, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (pola[i][j]->isAvailable() == 0) {
                return true;
            }
        }
    }
    return false;
}
