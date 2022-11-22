#pragma once
#include <string>
#include "Party.h"
#include "Agent.h"

using std::string;
class Agent;

class JoinPolicy 
{
    public:
        JoinPolicy();
        virtual ~JoinPolicy();
        virtual Agent Choose(Agent &aAgent,Agent &bAgent)=0;
        virtual int whichPolicy();
};

class MandatesJoinPolicy : public JoinPolicy 
{
    public:
        MandatesJoinPolicy();
        Agent Choose(Agent &aAgent,Agent &bAgent) override;
        int whichPolicy() override;
    
};

class LastOfferJoinPolicy : public JoinPolicy 
{
    public:
        LastOfferJoinPolicy();
        Agent Choose(Agent &aAgent,Agent &bAgent) override;
        int whichPolicy() override;
};