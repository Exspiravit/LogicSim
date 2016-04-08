#include "Input.h"

#include "Output.h"
#include "Bar.h"

Input::Input(sf::RenderWindow* pWind)
{
    this->pWind = pWind;
    GraphicsInfo GfxInfo;
    GfxInfo.x = 0;
    GfxInfo.y = 0;                      ///TO-BE-EDITED
    GfxInfo.Height = 700;               ///TO-BE-EDITED
    GfxInfo.Width = 65;                 ///TO-BE-EDITED
    DesignBar = new Bar(GfxInfo);
    GfxInfo.x = 0;
    GfxInfo.y = 700;                    ///TO-BE-EDITED
    GfxInfo.Height = 50;                ///TO-BE-EDITED
    GfxInfo.Width = 1000;               ///TO-BE-EDITED
    SimulationBar = new Bar(GfxInfo);
    ActiveBar = DesignBar;
    GfxInfo.Height = 55;
    GfxInfo.Width = 55;
    GfxInfo.x = 5;
    GfxInfo.y = 5;
    DesignBar->AddButton(GfxInfo, "add", ADD);
    GfxInfo.y = 65;
    DesignBar->AddButton(GfxInfo, "delete", DEL);
    GfxInfo.y = 125;
    DesignBar->AddButton(GfxInfo, "copy", COPY);
    GfxInfo.y = 185;
    DesignBar->AddButton(GfxInfo, "cut", CUT);
    GfxInfo.y = 245;
    DesignBar->AddButton(GfxInfo, "paste", PASTE);

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
