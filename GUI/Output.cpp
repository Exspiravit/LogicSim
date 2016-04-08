#include "Output.h"

#include "UI_Info.h"
#include "Input.h"
#include "Bar.h"

Output::Output()
{
    UI.BarColor = sf::Color(0x7a, 0x7a, 0x7a);
    UI.BorderColor = sf::Color::Black;
    UI.ConnectionColor = sf::Color::Black;
    UI.BackgroundColor = sf::Color::White;
    UI.GridColor = sf::Color(0xb4, 0xb4, 0xb4);
    UI.Title = "Logic Simulator";

    pWind = new sf::RenderWindow(sf::VideoMode(UI.WindowWidth,UI.WindowHeight), UI.Title);
    GraphicsInfo GfxInfo;
    GfxInfo.x = 0;
    GfxInfo.y = UI.WindowHeight - UI.StatusBarHeight;
    GfxInfo.Height = UI.WindowHeight;
    GfxInfo.Width = UI.WindowWidth;
    StatusBar = new Bar(GfxInfo);
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
    Rectangle.setSize(sf::Vector2f(GfxInfo.Width, GfxInfo.Height));
    Rectangle.setPosition(GfxInfo.x, GfxInfo.y);
    Rectangle.setFillColor(UI.BarColor);
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
    Sprite.setPosition(GfxInfo.x, GfxInfo.y);
    if(Pressed)
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
        for(int i = 20; i < UI.WindowHeight - UI.StatusBarHeight; i+=20)
        {
            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(UI.ToolBarWidth, i), UI.GridColor),
                sf::Vertex(sf::Vector2f(UI.WindowWidth, i), UI.GridColor)
            };
            pWind->draw(line, 2, sf::Lines);
        }
        for(int i = UI.ToolBarWidth + 20; i < UI.WindowWidth; i+=20)
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
    pWind->display();
}
