#include "ApplicationManager.h"

#include "GUI/Output.h"
#include "GUI/Input.h"
#include "GUI/Canvas.h"

ApplicationManager::ApplicationManager()
{
    SimCanvas = new Canvas;
    OutputInterface = new Output();
    InputInterface = OutputInterface->CreateInput();
}

ApplicationManager::~ApplicationManager()
{
    delete SimCanvas;
    delete OutputInterface;
}

ActionType ApplicationManager::GetUserAction()
{
    return InputInterface->GetUserAction();
}

void ApplicationManager::ExecuteAction(ActionType)
{
    ///TODO
}

void ApplicationManager::UpdateInterface()
{
    SimCanvas->Draw(OutputInterface);
    InputInterface->Update(OutputInterface);
    OutputInterface->UpdateWindow();
    ///TO-BE-CONTINUED
}

Output* ApplicationManager::GetOutput()
{
    return OutputInterface;
}

Input* ApplicationManager::GetInput()
{
    return InputInterface;
}

Canvas* ApplicationManager::GetCanvas()
{
    return SimCanvas;
}
