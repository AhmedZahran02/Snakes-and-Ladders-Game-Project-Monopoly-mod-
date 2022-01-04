#pragma once
#include "Card.h"
class CardTwelve :
    public Card
{
public:
    CardTwelve(const CellPosition& pos);

    virtual void ReadCardParameters(Grid* pGrid);

    virtual void Apply(Grid* pGrid, Player* pPlayer);

    virtual ~CardTwelve();
};

