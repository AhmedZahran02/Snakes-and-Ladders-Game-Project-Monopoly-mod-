#pragma once
#include "Card.h"

class CardNineToEleven : public Card
{
	//Parameters:
	int CardPrice;
	int Fees;
	Player* owner;
public:
	CardNineToEleven(const CellPosition& pos,int cardnum); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card on the passed Player

	virtual ~CardNineToEleven(); // A Virtual Destructor
};


