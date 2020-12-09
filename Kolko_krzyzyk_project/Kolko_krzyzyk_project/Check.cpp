#include "Check.h"
#include <iostream>

int Check::czyWygrana(std::vector<std::vector<Field*>> pola, int rozmiar)
{
	int licznik_y = 0, licznik_x = 0;
	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			if( pola[j][i]->getText().getString().toAnsiString() == "X") // Do poprawy warunek z sf::Text na chara czy coœ
			{
				licznik_y++;
			}
			else {
				licznik_y = 0;
			}
		}
	}
	return 0;
}
