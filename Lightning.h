#pragma once
#include "Attack.h"
class Lightning :
    public Attack
{
private:
	// [Action Parameters]
public:
	Lightning(); // A Constructor

	virtual void Execute(Grid* pGrid, Player* pPlayer);

	virtual ~Lightning(); // A Virtual Destructor
};
