#pragma once
#include "Card.h"
class CardEight :
    public Card
{
    static int bailMoney;
    static int arrRemDays[4];
    static bool arrJailedPlayers[4];
    static bool done;
public:
    CardEight(CellPosition& pos);

    virtual ~CardEight();

    virtual void ReadCardParameters(Grid* pGrid);

    virtual void Apply(Grid* pGrid, Player* pPlayer);

    bool isJailed(int playerNum) const;

    int GetRemDays(int playerNum) const;

    void DecrementRemDays(int playerNum);

    //virtual void Save(ofstream& outFile, int Type);

    void free(int playerNum);
};

