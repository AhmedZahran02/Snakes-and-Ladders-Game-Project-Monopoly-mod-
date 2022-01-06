#pragma once
#include "CardNineToEleven.h"

class CardNine : public CardNineToEleven
{
	//Parameters:
	static int CardPrice;
	static int Fees;
	static Player* card9owner;
	static bool done;
public:
	CardNine(const CellPosition& pos); // A Constructor takes card position

	static void setowner(Player* p);

	static void nullowner();

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card 9

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card on the passed Player

	virtual void Save(ofstream& outFile, int Type);

	virtual ~CardNine(); // A Virtual Destructor
};
