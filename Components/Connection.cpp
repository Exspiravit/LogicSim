#include "Connection.h"

#include "../GUI/Output.h"

Connection::Connection()
{

}

void Connection::Draw(Output* pOut)
{
    pOut->DrawConnection(Vertices);
}
