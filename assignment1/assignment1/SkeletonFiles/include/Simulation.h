#pragma once

#include <vector>


#include "Agent.h"
#include "Party.h"
#include "Graph.h"

using std::string;
using std::vector;
class Coalition;
class Graph;
class Agent;
class Party;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);
    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    void addCoalition(Coalition coalition);
    vector<Coalition> mCoalitions;
    vector<Agent> getAgentsList() const;
    

private:
    Graph mGraph;
    vector<Agent> mAgents;
    std::pair<int,int> max;//first is mandates number second id
    bool didAgentsFinish() const;
};
