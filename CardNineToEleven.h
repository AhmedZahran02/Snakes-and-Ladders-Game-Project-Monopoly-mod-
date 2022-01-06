#pragma once
#include "Card.h"

class CardNineToEleven : public Card
{
private:

public:
	CardNineToEleven(const CellPosition& pos,int cardnum);

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card9-11

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card9-11 on the passed Player

	//virtual void Save(ofstream& outFile, int Type);
};

