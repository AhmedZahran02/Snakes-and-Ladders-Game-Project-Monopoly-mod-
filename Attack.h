#pragma once
#include "Action.h"
class Attack :
    public Action
{
private:
	// [Action Parameters]
	int Remainingattacks;            // 1- the attacks remanning to the player
	// Note: These parameters should be read in ReadActionParameters()
public:
	Attack(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads action parameters

	virtual void Execute(); 

	virtual ~Attack(); // A Virtual Destructor
};
