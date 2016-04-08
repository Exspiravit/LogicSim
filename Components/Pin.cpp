#include "Pin.h"

Pin::Pin()
{
	m_Status = LOW;	//Default Status is LOW
}

void Pin::SetStatus(STATUS r_Status)
{
	m_Status = r_Status;
}

STATUS Pin::GetStatus()
{
	return m_Status;
}
