#include "Bar.h"

#include "Output.h"
#include "Button.h"

Bar::Bar(const GraphicsInfo& r_GfxInfo)
{
    m_GfxInfo.x = r_GfxInfo.x;
    m_GfxInfo.y = r_GfxInfo.y;
    m_GfxInfo.Height = r_GfxInfo.Height;
    m_GfxInfo.Width = r_GfxInfo.Width;
}

Bar::~Bar()
{
    for(unsigned int i = 0; i < Buttons.size(); i++)
        delete Buttons[i];
}

void Bar::Draw(Output* pOut)
{
    pOut->DrawBar(m_GfxInfo);
    for(unsigned int i = 0; i < Buttons.size(); i++)
        Buttons[i]->Draw(pOut);
}

void Bar::AddButton(const GraphicsInfo& r_GfxInfo, const std::string& r_ImagePath, ActionType r_Act)
{
    Button* pButton = new Button(r_GfxInfo, r_ImagePath, r_Act);
    Buttons.push_back(pButton);
}

const GraphicsInfo& Bar::GetGraphicsInfo() const
{
    return m_GfxInfo;
}

const std::vector<Button*>& Bar::GetButtons() const
{
    return Buttons;
}
