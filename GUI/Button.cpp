#include "Button.h"

#include "Output.h"

Button::Button(const GraphicsInfo& r_GfxInfo, const std::string& r_ImagePath, ActionType r_Act): m_GfxInfo(r_GfxInfo)
{
    m_ImagePath = r_ImagePath;
    m_Act = r_Act;
    m_Pressed = false;
}

Button::~Button(){}

void Button::Draw(Output* pOut)
{
    pOut->DrawButton(m_GfxInfo, m_ImagePath, m_Pressed);
}

void Button::SetStatus(bool r_Pressed)
{
    m_Pressed = r_Pressed;
}

ActionType Button::GetAction() const
{
    return m_Act;
}

const GraphicsInfo& Button::GetGraphicsInfo() const
{
    return m_GfxInfo;
}
