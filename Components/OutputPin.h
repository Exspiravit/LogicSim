#pragma once

#include "Pin.h"

#include <vector>

class Connection;

class OutputPin: public Pin
{
private:
	std::vector<Connection*> Connections;
	int m_FanOut;

public:
	OutputPin(int r_FanOut);
	bool ConnectTo(Connection *r_Conn);
};
