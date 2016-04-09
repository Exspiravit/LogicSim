#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo, std::string r_Label): m_GfxInfo(r_GfxInfo)
{
    m_Label = r_Label;
}

Component::~Component(){}
