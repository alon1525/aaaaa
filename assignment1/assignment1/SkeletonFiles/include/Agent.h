#pragma once
#include <vector>
#include "Graph.h"
#include "Party.h"
#include "Simulation.h"
#include "Coalition.h"
#include "SelectionPolicy.h"
#include <queue>

using namespace std;
class Party;
class Simulation;
class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    Party getParty() const;
    Coalition agentCoalition = Coalition(*this);
    bool isOriginal;
    virtual ~Agent();//destructor
    Agent(const Agent &other);//copy constractor
    Agent(Agent&& other);
    Agent& operator=(const Agent &other);
    Agent& operator=(Agent &&other);
    queue<Party> pickingOrder;
    int getSelectionPolicy() const;
    bool start;

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    Party *agentsParty; 
    
    
    
};
