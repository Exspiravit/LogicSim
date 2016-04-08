#pragma once

#include <vector>

class Output;

class Connection
{
public:
    Connection();
    void Draw(Output* pOut);

private:
    std::vector< std::pair<int,int> > Vertices;
};
