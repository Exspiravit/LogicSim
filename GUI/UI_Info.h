#pragma once

#include "../Defs.h"

#include <SFML/Graphics.hpp>
#include <string>

struct UI_Info
{
	MODE AppMode;

	static const int	WindowWidth = 1000,
                        WindowHeight = 750,
						StatusBarHeight = 50,
						ToolBarWidth = 65,
						BarBorderThickness = 4,
						ButtonWidth = 55,
						ButtonHeight = 55,
						GridSize = 20;

	sf::Color BarColor;
	sf::Color BorderColor;
	sf::Color ConnectionColor;
	sf::Color BackgroundColor;
	sf::Color GridColor;

	std::string Title;

	static const int	Gate_Width = 60,
						Gate_Height = 60;

}static UI;

