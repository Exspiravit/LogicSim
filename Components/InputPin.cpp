#include "InputPin.h"

InputPin::InputPin()
{}

void InputPin::SetComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::GetComponent()
{
	return pComp;
}
