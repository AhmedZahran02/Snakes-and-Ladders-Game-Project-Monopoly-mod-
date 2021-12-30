#pragma once
#include "Card.h"
class CardTwo :
    public Card
{

public:

    CardTwo(const CellPosition& pos); // A Constructor takes card position

    virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFour on the passed Player

    virtual ~CardTwo(); //A virtual Destructor
};

