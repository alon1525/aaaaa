#include "Graph.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

vector<Party> Graph::getmVertices() const{return mVertices;}

const std::vector<std::pair<int,Party>> Graph::getNeighboors(Party curr) const
{
    std::vector<std::pair<int,Party>> a = std::vector<std::pair<int,Party>>();
    for(Party ver : mVertices)
    {
        if (ver.getmId() != curr.getmId())
        {
            int edgeWeight = getEdgeWeight(curr.getmId(),ver.getmId());
            if (edgeWeight>0)
            {
                a.push_back(std::pair<int,Party>(edgeWeight,ver));
            }
            
        }
        
    }
    return a;
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}


int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}