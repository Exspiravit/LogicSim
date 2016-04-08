#pragma once

#include "../Defs.h"

#include <string>

class Output;

class Component
{
protected:
	GraphicsInfo m_GfxInfo;
	std::string m_Label;

public:
	Component(const GraphicsInfo &r_GfxInfo, std::string r_Label);
	virtual void Operate()=0;
	virtual void Draw(Output* pOut)=0;
	virtual int GetOutputPinStatus()=0;
	virtual int GetInputPinStatus(int n)=0;
	virtual void SetInputPinStatus(int n, STATUS s)=0;
	virtual ~Component();
};
