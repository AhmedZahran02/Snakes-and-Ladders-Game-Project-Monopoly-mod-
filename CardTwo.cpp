#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer) {
	Output* pOut = pGrid->GetOutput();
	CellPosition CellPositionOfPlayer = pPlayer->GetCell()->GetCellPosition();
	Ladder* NextLadder = pGrid->GetNextLadder(CellPositionOfPlayer);

	if (NextLadder == NULL) {
		pOut->PrintMessage("No Next Ladder exists! The player will not move.");
	}
	else {
		

	}

}
CardTwo::~CardTwo() {

}