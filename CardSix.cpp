#include "CardSix.h"
CardSix::CardSix(const CellPosition& pos)
	: Card(pos)
{
	cardNumber = 6;
}

void CardSix::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please enter X coordinate of cell: ");
	XdestinationCell = pIn->GetInteger(pOut);
	pOut->PrintMessage("Please enter Y coordinate of cell: ");
	YdestinationCell = pIn->GetInteger(pOut);
}


void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Cell destinationCell(YdestinationCell, XdestinationCell);
	pGrid->UpdatePlayerCell(pPlayer, destinationCell.GetCellPosition());
	GameObject* obj = destinationCell.GetGameObject();
	if (obj) {
		obj->Apply(pGrid, pPlayer);
	}
}


CardSix::~CardSix()
{

}