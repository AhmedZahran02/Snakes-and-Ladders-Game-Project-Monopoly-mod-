#pragma once

#include "Card.h"
#include "RollDiceAction.h"

class CardThree : public Card
{
	
public:
	CardThree(const CellPosition& pos); // A Constructor takes card position


	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
													  
	//virtual void Save(ofstream& outFile, int Type);

	virtual ~CardThree(); // A Virtual Destructor
};

