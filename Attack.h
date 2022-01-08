#pragma once
#include "Action.h"
class Attack :
    public Action
{
private:
	// [Action Parameters]
	int Remainingattacks;            // 1- the attacks remanning to the player
	int attacknumber;
	// Note: These parameters should be read in ReadActionParameters()
public:
	Attack(ApplicationManager* pApp,int attacknum); // A Constructor

	virtual void ReadActionParameters(); // Reads action parameters

	virtual void Execute(Grid* pGrid, Player* pPlayer);

	virtual ~Attack(); // A Virtual Destructor
};
