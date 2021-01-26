#pragma once

#include "Field.h"

/// <summary>
/// Klasa obs³uguj¹ca AI oparte na losowaniu wspó³rzêdnych dla ruchu komputera.
/// </summary>
class AiLow
{
	/// <summary>
	/// Wspó³rzêdne wykonywanego ruchu
	/// </summary>
	int wsp_y, wsp_x;
public:
	void moveAiLow(std::vector<std::vector<Field*>> pola, int size);
	/// <summary>
	/// Funkcja zwracaj¹ca wspó³rzêdn¹ Y dla ruchu
	/// </summary>
	/// <returns> wspó³rzêdna y</returns>
	int getY();
	/// <summary>
	/// Funkcja zwracaj¹ca wspó³rzêdn¹ X dla ruchu
	/// </summary>
	/// <returns> wspó³rzêdna x</returns>
	int getX();
};

