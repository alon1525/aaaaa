#include "JoinPolicy.h"
#include <string>

using std::string;

Agent MandatesJoinPolicy::Choose(Agent &aAgent, Agent &bAgent)
{
    if (aAgent.agentCoalition.getTotalMandates()< bAgent.agentCoalition.getTotalMandates())
    {
        return bAgent;
    }
    else
    {
        return aAgent;
    }
}

int MandatesJoinPolicy::whichPolicy()
{
    return 1;
}

int LastOfferJoinPolicy::whichPolicy()
{
    return 2;
}

Agent LastOfferJoinPolicy::Choose(Agent &aAgent, Agent &bAgent)
{
    return bAgent;      
}