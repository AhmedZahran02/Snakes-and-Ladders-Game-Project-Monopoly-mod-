#pragma once
#include "Card.h"

class CardFour : public Card
{
private:
	bool Freed = true;
	static bool Card4Players[MaxPlayerCount];
	
public:

	CardFour(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFour on the passed Player

	bool isCard4Players(int playerNum) const;

	bool isfree() const;

	void free(int playerNum);

	virtual void Save(ofstream& outFile, int Type);

	virtual void Open(ifstream& inFile);

	virtual ~CardFour(); // A Virtual Destructor
};
