#pragma once
#include <vector>
#include "Party.h"

using std::vector;
class Party;

class Graph
{
public:
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    const Party &getParty(int partyId) const;
    Graph(const Graph &other);
    const std::vector<std::pair<int,Party>> getNeighboors(Party curr) const;
    vector<Party> getmVertices() const;

private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};
