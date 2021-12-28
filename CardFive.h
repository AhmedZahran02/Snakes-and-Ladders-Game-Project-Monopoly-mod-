#pragma once
#include "Card.h"
class CardFive : public Card
{
public:
	void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardFive();
};

