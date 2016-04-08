#pragma once

#include "Pin.h"

class Component;

class InputPin: public Pin
{
private:
	Component* pComp;

public:
	InputPin();
	void SetComponent(Component* pCmp);
	Component* GetComponent();
};
