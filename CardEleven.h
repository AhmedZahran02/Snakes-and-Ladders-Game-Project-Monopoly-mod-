#pragma once
#include "Card.h"

class CardEleven : public Card
{
	//Parameters:
	static int CardPrice;
	static int Fees;
	static Player* card11owner;
	static bool done;
public:
	CardEleven(const CellPosition& pos); // A Constructor takes card position

	void setowner(Player* p);

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card on the passed Player

	virtual ~CardEleven(); // A Virtual Destructor
};



