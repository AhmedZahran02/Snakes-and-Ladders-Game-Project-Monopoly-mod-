#pragma once

#include "Card.h"

class CardFour : public Card
{
private:
	static int arrRemRolls[MaxPlayerCount];
	static bool Card4Players[MaxPlayerCount];
public:
	CardFour(const CellPosition& pos); // A Constructor takes card position


	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFour on the passed Player

	bool isCard4Players(int playerNum) const;

	int GetRemRolls(int playerNum) const;

	void DecrementRemRolls(int playerNum);

	void free(int playerNum);

	//virtual void Save(ofstream& outFile, int Type);

	virtual ~CardFour(); // A Virtual Destructor
};
