#include "Gate.h"

Gate::Gate(const GraphicsInfo &r_GfxInfo, std::string r_Label, int r_Inputs, int r_FanOut): Component(r_GfxInfo, r_Label), m_OutputPin(r_FanOut)
{
     m_Inputs = r_Inputs;
     m_InputPins = new InputPin[m_Inputs];
}

Gate::~Gate()
{
    delete[] m_InputPins;
}
