#pragma once

#include "Card.h"
#include "RollDiceAction.h"

class CardThree : public Card
{
	// CardOne Parameters:
	int walletAmount; // the wallet value to decrease from the player

public:
	CardThree(const CellPosition& pos); // A Constructor takes card position


	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
													  

	virtual ~CardThree(); // A Virtual Destructor
};

