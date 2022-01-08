#pragma once
#include "Attack.h"
class Lightning :
    public Attack
{
private:
	// [Action Parameters]
public:
	Lightning(ApplicationManager* pApp); // A Constructor

	virtual void Execute(Grid* pGrid, Player* pPlayer);

	virtual ~Lightning(); // A Virtual Destructor
};
