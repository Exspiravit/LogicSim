#pragma once

#include "../Defs.h"

#include <string>

class Output;

class Component
{
private:
	GraphicsInfo m_GfxInfo;
	std::string m_Label;
	bool m_Selected;

public:
	Component(const GraphicsInfo &r_GfxInfo, std::string r_Label,bool r_Selected=true);
	virtual ~Component();

	const GraphicsInfo& GetGraphicsInfo() const;
	void SetGraphicsInfo(const GraphicsInfo  &r_GfxInfo) ;
	std::string GetLabel();
	void SetLabel(std::string r_Label);
	void SetSelcted(bool r_Selected);

	virtual void Operate()=0;
	virtual void Draw(Output* pOut)=0;
	virtual int GetOutputPinStatus()=0;
	virtual int GetInputPinStatus(int n)=0;
	virtual void SetInputPinStatus(int n, STATUS s)=0;
	
};

