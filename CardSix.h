#pragma once
#include "Card.h"
class CardSix :
    public Card
{
    int XdestinationCell;
    int YdestinationCell;
public:
    CardSix(const CellPosition & pos);
    void ReadCardParameters(Grid* pGrid);
    void Apply(Grid* pGrid, Player* pPlayer);
    ~CardSix();
};

