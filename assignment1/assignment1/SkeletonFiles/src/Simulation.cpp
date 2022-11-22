#include <Simulation.h>
#include "Graph.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents),mCoalitions(),max(0,0) 
{
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step()
{
    if (!shouldTerminate())
    {
       for (Party party : mGraph.getmVertices())
        {
            party.step(*this);
        }
        for (Agent agent : mAgents)
        {
            agent.step(*this);
        }
        for (Coalition coalition : mCoalitions)
        {
            if (max.first<coalition.getTotalMandates())
            {
                max.first = coalition.getTotalMandates();
                max.second = coalition.getCoalitionId();
            }
        }
         
    }
    
}

std::vector<Agent> Simulation::getAgentsList() const{return mAgents;}

void Simulation::addCoalition(Coalition coalition)
{
    if (max.first<coalition.getTotalMandates())
    {
        max.first = coalition.getTotalMandates();
        max.second = coalition.getCoalitionId();
    }
    
    mCoalitions.push_back(coalition);
}

bool Simulation::didAgentsFinish() const
{
    for (Agent agent : mAgents)
    {
        if (agent.pickingOrder.empty() == false)
        {
            return false;
        }
        
    }
    return true;
    
}

bool Simulation::shouldTerminate() const
{
    if (max.first >= 61)
    {
        return true;
    }
    else if (didAgentsFinish())
    {
        return true;
    }
    else{
        return false;
    }
    
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<vector<int>> allParties = vector<vector<int>>();
    for (Coalition coalition : mCoalitions)
    {
        vector<int> curCoalition = vector<int>();
        for (int partyId : coalition.coalitionList)
        {
            curCoalition.push_back(partyId);
        }
        allParties.push_back(curCoalition);
    }
    
    return allParties;
}
