#pragma once
#include "Card.h"

class CardNine : public Card
{
	//Parameters:
	static int CardPrice;
	static int Fees;
	static Player* card9owner;
	static bool done;
public:
	CardNine(const CellPosition& pos); // A Constructor takes card position

	static void setowner(Player* p);

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card on the passed Player

	virtual ~CardNine(); // A Virtual Destructor
};
