#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class ResourceMenager
{
private:
	std::map<std::string, sf::Font*> fontMap;
	bool addFont(std::string name);
public:
	ResourceMenager();
	virtual ~ResourceMenager();
	sf::Font* getFont(std::string name);
};

