#include "OutputPin.h"

#include "Connection.h"

OutputPin::OutputPin(int r_FanOut)
{
	m_FanOut = r_FanOut;
}
/*
//Functionn ConnectTo:
//Connects the ouput pin the the passed connection if the fan out permits
//if the no. of connections is already equals to the fan out, no more connections can be created.
bool OutputPin::ConnectTo(Connection *r_Conn)
{
	if(m_Conn < m_FanOut)
	{
		m_Connections[m_Conn++] = r_Conn;	//add a new connection the the array of connections
		return true;
	}

	return false;	//can't connect to any more connections
}
*/
