#pragma once
#include "Card.h"
class CardFive : public Card
{
public:
	CardFive::CardFive(const CellPosition& pos);
	void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardFive();
};

