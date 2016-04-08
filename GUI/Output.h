#pragma once

#include "../Defs.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Input;
class Bar;

class Output
{
private:
	sf::RenderWindow* pWind;
	Bar* StatusBar;

public:
	Output();
	~Output();
	Input* CreateInput() const;
	void PrintMsg(std::string msg);
	void ClearStatusBar();
	void DrawBar(GraphicsInfo GfxInfo);
	void DrawButton(GraphicsInfo GfxInfo, std::string ImagePath, bool Pressed = false);
	void DrawCanvas(bool ShowGrid = true);
	void DrawGate(GraphicsInfo GfxInfo, std::string ImagePath, bool Selected = false);
	void DrawPin(std::pair<int,int> Point, bool Connected);
	void DrawConnection(const std::vector< std::pair<int,int> >& Vertices, bool Selected = false);
	void UpdateWindow();
};
