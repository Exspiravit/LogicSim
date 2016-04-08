#pragma once

#include "../Defs.h"

class Pin
{
protected:
	STATUS m_Status;

public:
	Pin();
	void SetStatus(STATUS r_Status);
	STATUS GetStatus();
};
