#pragma once

#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

#include <string>

class Gate: public Component
{
protected:
	InputPin* m_InputPins;
	OutputPin m_OutputPin;
	int m_Inputs;

public:
	Gate(const GraphicsInfo &r_GfxInfo, std::string r_Label, int r_Inputs, int r_FanOut);
	~Gate();
};
