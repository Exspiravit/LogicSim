#pragma once

#include "../Defs.h"

#include <string>

class Output;

class Button
{
public:
    Button(const GraphicsInfo& r_GfxInfo, const std::string& r_ImagePath, ActionType r_Act);
    ~Button();
    void Draw(Output* pOut);
    void SetStatus(bool r_Pressed = false);
    ActionType GetAction() const;
    const GraphicsInfo& GetGraphicsInfo() const;

private:
    GraphicsInfo m_GfxInfo;
    std::string m_ImagePath;
    ActionType m_Act;
    bool m_Pressed;
};
