#pragma once

#include "../Defs.h"

#include <SFML/Graphics.hpp>

class ApplicationManager;
class Output;
class Bar;

class Input
{
private:
	sf::Window *pWind;
	Bar* DesignBar;
	Bar* SimulationBar;
	Bar* ActiveBar;

public:
	Input(sf::RenderWindow* pWind);
	~Input();
	std::pair<int,int> GetPointClicked();
	std::pair<int,int> GetMousePosition();
	bool IsLeftButtonPressed();
	std::string GetSrting(Output* pOut);
	ActionType GetUserAction() const;
	void Update(Output* pOut);
};
