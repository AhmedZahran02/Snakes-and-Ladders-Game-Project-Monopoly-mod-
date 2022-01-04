#include "CardFive.h"





CardFive::CardFive(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (1 here)
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int diceNumber = pPlayer->GetJustRolledDiceNum();
	CellPosition destination = pPlayer->GetCell()->GetCellPosition();
	destination.AddCellNum(-1 * diceNumber);
	pPlayer->SetStepCount(destination.GetCellNum());
	pGrid->UpdatePlayerCell(pPlayer, destination);
	pGrid->UpdateInterface();
	GameObject* pObj  = pPlayer->GetCell()->GetGameObject();
	if (dynamic_cast<Card*>(pObj))
		pObj->Apply(pGrid, pPlayer);
}

CardFive::~CardFive()
{
}
