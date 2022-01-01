#include "CardThree.h"
#include "ApplicationManager.h"

CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (1 here)
}

CardThree::~CardThree(void)
{
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- give the pPlayer an extra dice roll
	pGrid->PrintErrorMessage("You have landed on Card 3, you now have an extra dice roll!");
	for (int i = 0; i < 3; i++) {
		pGrid->AdvanceCurrentPlayer();
	}
}
