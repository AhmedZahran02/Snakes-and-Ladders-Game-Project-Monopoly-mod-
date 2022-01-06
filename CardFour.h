#pragma once

#include "Card.h"

class CardFour : public Card
{
public:
	CardFour(const CellPosition& pos); // A Constructor takes card position


	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFour on the passed Player

	//virtual void Save(ofstream& outFile, int Type);

	virtual ~CardFour(); // A Virtual Destructor
};
