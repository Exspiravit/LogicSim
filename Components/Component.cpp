#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo, std::string r_Label, bool isSelcted ) : m_GfxInfo(r_GfxInfo), m_Selected(isSelcted)
{
	SetLabel(r_Label);
}

Component::~Component(){}
const GraphicsInfo& Component::GetGraphicsInfo() const
{
	return m_GfxInfo;
}
void Component::SetGraphicsInfo(const GraphicsInfo  &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
}
std::string Component::GetLabel()
{
	return m_Label;
}
void Component::SetLabel(std::string r_Label)
{
	m_Label = r_Label;
}
