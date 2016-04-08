#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo, std::string r_Label)
{
    m_GfxInfo.x = r_GfxInfo.x;
    m_GfxInfo.y = r_GfxInfo.y;
    m_GfxInfo.Height = r_GfxInfo.Height;
    m_GfxInfo.Width = r_GfxInfo.Width;
    m_Label = r_Label;
}

Component::~Component(){}
