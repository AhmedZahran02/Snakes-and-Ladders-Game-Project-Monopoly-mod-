#pragma once
#include "Attack.h"
class Lightning :
    public Attack
{
private:
	// [Action Parameters]
	bool done;
public:
	Lightning(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads action parameters

	virtual void Execute(Grid* pGrid, Player* pPlayer);

	virtual ~Lightning(); // A Virtual Destructor
};
