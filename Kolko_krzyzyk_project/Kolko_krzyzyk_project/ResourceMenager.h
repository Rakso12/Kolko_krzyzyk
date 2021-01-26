#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

/// <summary>
/// Klasa odpowiedzialna za przydzia³ zasobów typu czcionki, tekstury itp.
/// </summary>
class ResourceMenager
{
private:
	/// <summary>
	/// mapa odpowiedzialna za przetrzymywanie czcionek
	/// </summary>
	std::map<std::string, sf::Font*> fontMap;
	/// <summary>
	/// funkcja dodaj¹ca czcionkê o podanej nazwie
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	bool addFont(std::string name);
public:
	ResourceMenager();
	/// <summary>
	/// Dekonstruktor zwracaj¹cy pamiêæ po zasobach
	/// </summary>
	virtual ~ResourceMenager();
	/// <summary>
	/// Funkcja przekazuj¹ca czcionkê o danej nazwie
	/// </summary>
	/// <param name="name"> nazwa czcionki </param>
	/// <returns> obiekt czcionki</returns>
	sf::Font* getFont(std::string name);
};
