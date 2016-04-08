#include "Canvas.h"

#include "Output.h"
#include "../Components/Component.h"
#include "../Components/Connection.h"

Canvas::Canvas()
{
    m_ShowGrid = true;
}

Canvas::~Canvas()
{
    for(unsigned int i = 0; i < Components.size(); i++)
        delete Components[i];
    for(unsigned int i = 0; i < Connections.size(); i++)
        delete Connections[i];
}

void Canvas::Draw(Output* pOut)
{
    pOut->DrawCanvas(m_ShowGrid);
    for(unsigned int i = 0; i < Components.size(); i++)
        Components[i]->Draw(pOut);
    for(unsigned int i = 0; i < Connections.size(); i++)
        Connections[i]->Draw(pOut);
}

void Canvas::AddComponent(Component* pComponent)
{
    Components.push_back(pComponent);
}

void Canvas::AddConnection(Connection* pConnection)
{
    Connections.push_back(pConnection);
}

void Canvas::SetGridStatus(bool Shown)
{
    m_ShowGrid = Shown;
}

const std::vector<Component*>& Canvas::GetComponents() const
{
    return Components;
}

const std::vector<Connection*>& Canvas::GetConnections() const
{
    return Connections;
}
