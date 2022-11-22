#pragma once
#include "Party.h"

class SelectionPolicy
{
    public:
        SelectionPolicy();
        virtual ~SelectionPolicy();
        virtual Party Choose(Party &aParty,Party &bParty,int edgeWeight1,int edgeWeight2)=0;  
        virtual int whichPolicy();  
};

class MandatesSelectionPolicy : public SelectionPolicy 
{
    public:
        MandatesSelectionPolicy();
        Party Choose(Party &aParty,Party &bParty,int edgeWeight1,int edgeWeight2) override;
        int whichPolicy() override;
    
};

class EdgeWeightSelectionPolicy : public SelectionPolicy 
{
    public:
        EdgeWeightSelectionPolicy();
        Party Choose(Party &aParty,Party &bParty,int edgeWeight1,int edgeWeight2) override;
        virtual int whichPolicy() override;
};