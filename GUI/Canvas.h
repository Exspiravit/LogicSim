#pragma once

#include <vector>

class Output;
class Component;
class Connection;

class Canvas
{
public:
    Canvas();
    ~Canvas();
    void Draw(Output* pOut);
    void AddComponent(Component* pComponent);
    void AddConnection(Connection* pConnection);
    void SetGridStatus(bool Shown);
    const std::vector<Component*>& GetComponents() const;
    const std::vector<Connection*>& GetConnections() const;

private:
    bool m_ShowGrid;
    std::vector<Component*> Components;
    std::vector<Connection*> Connections;
};
