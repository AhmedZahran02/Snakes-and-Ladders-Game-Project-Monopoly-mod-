#include "CardFour.h"
#include "ApplicationManager.h"
#include "RollDiceAction.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (1 here)
}

CardFour::~CardFour(void)
{
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- prevent the pPlayer from the next dice roll
	pGrid->PrintErrorMessage("You have landed on Card 4, you are prevented from rolling the next turn!");
	if (true)
	{
		int x = pPlayer->GetJustRolledDiceNum();
		pPlayer->Move(pGrid, -x);
	}
}
