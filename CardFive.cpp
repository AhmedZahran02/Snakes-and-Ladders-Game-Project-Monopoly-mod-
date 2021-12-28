#include "CardFive.h"
void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	pPlayer->Move(pGrid, pPlayer->GetJustRolledDiceNum());
	GameObject* obj = pPlayer->GetCell()->GetGameObject();
	if (obj) {
		obj->Apply(pGrid, pPlayer);
	}
}

CardFive::~CardFive()
{
}
