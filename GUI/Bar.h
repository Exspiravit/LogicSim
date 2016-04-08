#pragma once

#include "../Defs.h"

#include <string>
#include <vector>

class Output;
class Button;

class Bar
{
public:
    Bar(const GraphicsInfo& r_GfxInfo);
    ~Bar();
    void Draw(Output* pOut);
    void AddButton(const GraphicsInfo& r_GfxInfo, const std::string& r_ImagePath, ActionType r_Act);
    const GraphicsInfo& GetGraphicsInfo() const;
    const std::vector<Button*>& GetButtons() const;

private:
    GraphicsInfo m_GfxInfo;
    std::vector<Button*> Buttons;
};
