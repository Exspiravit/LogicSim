#include "Input.h"

#include "UI_Info.h"
#include "Output.h"
#include "Bar.h"

Input::Input(sf::RenderWindow* pWind)
{
    this->pWind = pWind;
    DesignBar = new Bar(GraphicsInfo(0, 0, UI.ToolBarWidth, UI.WindowHeight - UI.StatusBarHeight));
    SimulationBar = new Bar(GraphicsInfo(0, 0, UI.ToolBarWidth, UI.WindowHeight - UI.StatusBarHeight));
    ActiveBar = DesignBar;
    DesignBar->AddButton(GraphicsInfo(5, 5, UI.ButtonWidth, UI.ButtonHeight), "add", ADD);
    DesignBar->AddButton(GraphicsInfo(5, 65, UI.ButtonWidth, UI.ButtonHeight), "delete", DEL);
    DesignBar->AddButton(GraphicsInfo(5, 125, UI.ButtonWidth, UI.ButtonHeight), "copy", COPY);
    DesignBar->AddButton(GraphicsInfo(5, 185, UI.ButtonWidth, UI.ButtonHeight), "cut", CUT);
    DesignBar->AddButton(GraphicsInfo(5, 245, UI.ButtonWidth, UI.ButtonHeight), "paste", PASTE);

    ///TO-BE-CONTINUED
}

Input::~Input()
{
    delete DesignBar;
    delete SimulationBar;
}

std::pair<int,int> Input::GetPointClicked()
{
    std::pair<int,int> PointClicked;
    ///SOME CODE HERE
    return PointClicked;
}

std::pair<int,int> Input::GetMousePosition()
{
    std::pair<int,int> MousePosition;
    ///SOME CODE HERE
    return MousePosition;
}

bool Input::IsLeftButtonPressed()
{
    ///SOME CODE HERE
    return true;
}

std::string Input::GetSrting(Output* pOut)
{
    ///SOME CODE HERE
    return "";
}

ActionType Input::GetUserAction() const
{
    sf::Event dummyEvent;
    pWind->pollEvent(dummyEvent);
    switch (dummyEvent.type)
    {
    case sf::Event::Closed:
        pWind->close();
        return EXIT;

    ///SOME CODE HERE

    default:
        return STATUS_BAR;
    }
}

void Input::Update(Output* pOut)
{
    ActiveBar->Draw(pOut);
}
