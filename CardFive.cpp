#include "CardFive.h"





CardFive::CardFive(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (1 here)
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	pPlayer->Move(pGrid, -1*pPlayer->GetJustRolledDiceNum());
	GameObject* obj = pPlayer->GetCell()->GetGameObject();
	if (obj) {
		obj->Apply(pGrid, pPlayer);
	}
}

CardFive::~CardFive()
{
}
