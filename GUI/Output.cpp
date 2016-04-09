#include "Output.h"

#include "UI_Info.h"
#include "Input.h"
#include "Bar.h"

Output::Output()
{
    UI.BarColor = sf::Color(0xbd, 0xc3, 0xc7);
    UI.BorderColor = sf::Color::Black;
    UI.ConnectionColor = sf::Color::Black;
    UI.BackgroundColor = sf::Color::White;
    UI.GridColor = sf::Color(0xb4, 0xb4, 0xb4);
    UI.Title = "Logic Simulator";

    pWind = new sf::RenderWindow(sf::VideoMode(UI.WindowWidth,UI.WindowHeight), UI.Title);
    StatusBar = new Bar(GraphicsInfo(0, UI.WindowHeight - UI.StatusBarHeight, UI.WindowWidth, UI.StatusBarHeight));
}

Output::~Output()
{
    delete pWind;
    delete StatusBar;
}

Input* Output::CreateInput() const
{
    return new Input(pWind);
}

void Output::PrintMsg(std::string msg)
{
    ///TODO
}

void Output::ClearStatusBar()
{
    ///TODO
}

void Output::DrawBar(GraphicsInfo GfxInfo)
{
    sf::RectangleShape Rectangle;
    Rectangle.setSize(sf::Vector2f(GfxInfo.GetWidth(), GfxInfo.GetHeight()));
    Rectangle.setPosition(GfxInfo.GetX(), GfxInfo.GetY());
    Rectangle.setFillColor(UI.BackgroundColor);
    Rectangle.setOutlineColor(UI.BorderColor);
    Rectangle.setOutlineThickness(UI.BarBorderThickness);
    pWind->draw(Rectangle);
}

void Output::DrawButton(GraphicsInfo GfxInfo, std::string ImagePath, bool Pressed)
{
    sf::Texture Texture;
    Texture.loadFromFile("Graphics/Buttons/"+ImagePath+".png");
    sf::Sprite Sprite;
    Sprite.setTexture(Texture);
    Sprite.setPosition(GfxInfo.GetX(), GfxInfo.GetY());
    if(Pressed||((Sprite.getGlobalBounds().contains(sf::Mouse::getPosition(*(pWind)).x, sf::Mouse::getPosition(*(pWind)).y))&&sf::Mouse::isButtonPressed(sf::Mouse::Left)))
        Sprite.setTextureRect(sf::IntRect(110, 0, 55, 55));
    else
        if(Sprite.getGlobalBounds().contains(sf::Mouse::getPosition(*(pWind)).x, sf::Mouse::getPosition(*(pWind)).y))
            Sprite.setTextureRect(sf::IntRect(55, 0, 55, 55));
        else
            Sprite.setTextureRect(sf::IntRect(0, 0, 55, 55));
    pWind->draw(Sprite);
}

void Output::DrawCanvas(bool ShowGrid)
{
    sf::RectangleShape Rectangle;
    Rectangle.setSize(sf::Vector2f(UI.WindowWidth - UI.ToolBarWidth, UI.WindowHeight - UI.StatusBarHeight));
    Rectangle.setPosition(UI.ToolBarWidth, 0);
    Rectangle.setFillColor(UI.BackgroundColor);
    pWind->draw(Rectangle);
    if(ShowGrid)
    {
        for(int i = 10; i < UI.WindowHeight - UI.StatusBarHeight; i+=10)
        {
            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(UI.ToolBarWidth, i), UI.GridColor),
                sf::Vertex(sf::Vector2f(UI.WindowWidth, i), UI.GridColor)
            };
            pWind->draw(line, 2, sf::Lines);
        }
        for(int i = UI.ToolBarWidth + 10; i < UI.WindowWidth; i+=10)
        {
            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(i, 0), UI.GridColor),
                sf::Vertex(sf::Vector2f(i, UI.WindowHeight - UI.StatusBarHeight), UI.GridColor)
            };
            pWind->draw(line, 2, sf::Lines);
        }
    }
}

void Output::DrawGate(GraphicsInfo GfxInfo, std::string ImagePath, bool Selected)
{
    ///TODO
}

void Output::DrawPin(std::pair<int,int> Point, bool Connected)
{
    ///TODO
}

void Output::DrawConnection(const std::vector< std::pair<int,int> >& Vertices, bool Selected)
{
    for(unsigned int i = 1; i < Vertices.size(); i++)
        {
            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(Vertices[i-1].first, Vertices[i-1].second),UI.ConnectionColor),
                sf::Vertex(sf::Vector2f(Vertices[i].first, Vertices[i].second),UI.ConnectionColor)
            };
            pWind->draw(line, 2, sf::Lines);
        }
}

void Output::UpdateWindow()
{
    StatusBar->Draw(this);
    sf::Texture Texture;
    Texture.loadFromFile("Graphics/Components/file.png");
    sf::Sprite Sprite;
    Sprite.setTexture(Texture);
    Sprite.setPosition(85, 20);
    pWind->draw(Sprite);
    pWind->display();
}
