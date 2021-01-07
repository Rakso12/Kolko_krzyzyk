#include "ResourceMenager.h"

ResourceMenager::ResourceMenager()
{
	addFont("../Resources/arial.ttf");
}

ResourceMenager::~ResourceMenager()
{
	for (auto const& font : fontMap) {
		delete font.second;
	}
}

sf::Font* ResourceMenager::getFont(std::string name)
{
	return fontMap[name];
}

bool ResourceMenager::addFont(std::string name)
{
	fontMap[name] = new sf::Font;
	if (!fontMap[name]->loadFromFile(name)) {
		std::cout << "Failed to load font:" << name << std::endl;
		return false;
	}
	return true;
}