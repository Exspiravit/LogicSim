#pragma once

#include "Defs.h"

class Output;
class Input;
class Canvas;

class ApplicationManager
{
private:
	Canvas* SimCanvas;
	Output* OutputInterface;
	Input* InputInterface;

public:
	ApplicationManager();
	~ApplicationManager();
	ActionType GetUserAction();
	void ExecuteAction(ActionType);
	void UpdateInterface();
	Output* GetOutput();
	Input* GetInput();
	Canvas* GetCanvas();
};

