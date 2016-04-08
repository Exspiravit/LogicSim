#pragma once

#include "Gate.h"

class AND2: public Gate
{
public:
	AND2(const GraphicsInfo &r_GfxInfo, std::string r_Label, int r_Inputs, int r_FanOut);
	virtual void Operate();
	virtual void Draw(Output* pOut);
	virtual int GetOutputPinStatus();
	virtual int GetInputPinStatus(int n);
	virtual void SetInputPinStatus(int n, STATUS s);
};
