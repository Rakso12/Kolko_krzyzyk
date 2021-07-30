#pragma once

#include "Check.h"

/// <summary>
/// Klasa obs�uguj�ca AI oparte na algorytmie MinMax - Niestety znalezione zostalo w nim du�o b��d�w kt�re wykluczaj� j� z dzia�ania.
/// </summary>
class AiMedium
{
	int wsp_x, wsp_y;
public:
	int bestVal = -1000;
	sf::Vector2i bestMove = sf::Vector2i(-1, -1);

	void moveAiMedium(std::vector<std::vector<Field*>> tmpBoard, std::vector<std::vector<Field*>> mainBoard, int size);
	/// <summary>
	/// Funkcja zwracaj�ca wsp�rz�dn� Y dla ruchu
	/// </summary>
	/// <returns> wsp�rz�dna y</returns>
	int getY();
	/// <summary>
	/// Funkcja zwracaj�ca wsp�rz�dn� X dla ruchu
	/// </summary>
	/// <returns> wsp�rz�dna x</returns>
	int getX();
	sf::Vector2i findBestMove(std::vector<std::vector<Field*>> tmpBoard, std::vector<std::vector<Field*>> mainBoard, int size, Check* check, char znak);
	int minMax(std::vector<std::vector<Field*>>pola, std::vector<std::vector<Field*>> mainBoard, int depth, bool isMax, int size, Check* check, int wsp_x, int wsp_y);
	bool isMovesLeft(std::vector<std::vector<Field*>>pola, int size);
};
