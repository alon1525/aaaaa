#pragma once
#include <string>
#include "Agent.h"
#include <utility>
#include "JoinPolicy.h"

using std::string;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    State getState() const;
    void setState(State state);
    int getMandates() const;
    int getmId() const;
    void step(Simulation &s);
    const string &getName() const;
    int timer;
    void recieveOffer(Agent *agent);
    virtual ~Party();//destructor
    Party(const Party &other);//copy constractor
    Party(Party&& other);
    Party& operator=(const Party &other);
    Party& operator=(Party &&other);

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    Agent *bestOfferedAgent;
};
