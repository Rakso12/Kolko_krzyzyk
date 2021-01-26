#pragma once

#include "Field.h"

/// <summary>
/// Klasa obs�uguj�ca AI oparte na losowaniu wsp�rz�dnych dla ruchu komputera.
/// </summary>
class AiLow
{
	/// <summary>
	/// Wsp�rz�dne wykonywanego ruchu
	/// </summary>
	int wsp_y, wsp_x;
public:
	void moveAiLow(std::vector<std::vector<Field*>> pola, int size);
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
};

