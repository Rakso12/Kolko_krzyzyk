#include "AiMedium.h"

/// <summary>
/// Funkcja uruchamiaj¹ca minmax 
/// </summary>
/// <param name="pola"> obiekt planszy </param>
/// <param name="size"> rozmiar planszy </param>
void AiMedium::moveAiMedium(std::vector<std::vector<Field*>> tmpBoard, std::vector<std::vector<Field*>> mainBoard, int size)
{
    Check sprawdz;
    sf::Vector2i move;

    move = findBestMove(tmpBoard, size, &sprawdz, 'O');

    mainBoard[move.y][move.x]->setText('O');
    mainBoard[move.y][move.x]->setUnAvailable();
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
/// <param name="copyPola"> obiekt planszy </param>
/// <param name="size"> rozmiar planszy </param>
/// <param name="check"> obiekt sprawdzania wygranej </param>
/// <param name="znak"> znak aktualnego gracza </param>
/// <returns></returns>
sf::Vector2i AiMedium::findBestMove(std::vector<std::vector<Field*>> copyPola, int size, Check* check, char znak)
{
    int bestVal = - 1000;
    sf::Vector2i bestMove = sf::Vector2i(-1, -1);

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (copyPola[i][j]->isAvailable() == 0) {
                
                copyPola[i][j]->setText(znak);
                copyPola[i][j]->setUnAvailable();
                int moveVal = minMax(copyPola, 0, false, size, check, i, j);
                copyPola[i][j]->setText('_');
                copyPola[i][j]->setAvailable();

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
/// <param name="copyPola"> obiekt planszy </param>
/// <param name="depth"> licznik wêz³a zagnie¿d¿enia</param>
/// <param name="isMax"> znacznik zawodnika </param>
/// <param name="size"> rozmiar planszy </param>
/// <param name="check"> obiekt sprawdzaj¹cy</param>
/// <param name="wsp_x"> wspó³rzêdna x wykonywanego ruchu </param>
/// <param name="wsp_y"> wspó³rzêdna y wykonywanego ruchu </param>
/// <returns></returns>
int AiMedium::minMax(std::vector<std::vector<Field*>> copyPola, int depth, bool isMax, int size, Check* check, int wsp_x, int wsp_y)
{
    int score = check->czyWygrana(copyPola, size, "0");  // Zero if X win / lub nie     1 jeœli 0 win
    if (score == 1) {
        score = 10;
        return score;
    }

    score = check->czyWygrana(copyPola, size, "X");
    if (score == 1){
        score = -10;
        return score;
    }

    if (isMovesLeft(copyPola, size) == false) return 0;

    if (isMax) {
        int best = -1000;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 3; j++) {
                if (copyPola[i][j]->isAvailable() == 0) 
                {
                    copyPola[i][j]->setText('O');
                    copyPola[i][j]->setUnAvailable();
                    best = std::max(best, minMax(copyPola, (depth + 1), !isMax, size, check, i, j));
                    copyPola[i][j]->setText('_');
                    copyPola[i][j]->setAvailable();
                }
            }
        }
        return best;
    }
    else {
        int best = 1000;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 3; j++) {
                if (copyPola[i][j]->isAvailable() == 0) 
                {
                    copyPola[i][j]->setText('X');
                    copyPola[i][j]->setUnAvailable();
                    best = std::min(best, minMax(copyPola, (depth + 1), !isMax, size, check, i, j));
                    copyPola[i][j]->setText('_');
                    copyPola[i][j]->setUnAvailable();

                }
            }
        }
        return best;
    }
}

/// <summary>
/// Funkcja sprawdzaj¹ca czy pozosta³y jakiekolwiek ruchy do wykonania na planszy
/// </summary>
/// <param name="copyPola"> obiekt planszy </param>
/// <param name="size"> rozmiar </param>
/// <returns></returns>
bool AiMedium::isMovesLeft(std::vector<std::vector<Field*>> copyPola, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (copyPola[i][j]->isAvailable() == 0) {
                return true;
            }
        }
    }
    return false;
}
