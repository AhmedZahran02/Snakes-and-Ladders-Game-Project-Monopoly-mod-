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
	do
	{
		pOut->PrintMessage("Please enter X coordinate of destination cell between 0 and 10 (inclusive): ");
		XdestinationCell = pIn->GetInteger(pOut);
	} while (XdestinationCell < 0 || XdestinationCell > 10);
	
	do
	{
		pOut->PrintMessage("Please enter Y coordinate of destination cell between 0 and 8 (inclusive): ");
		YdestinationCell = pIn->GetInteger(pOut);
	} while (YdestinationCell < 0 || YdestinationCell > 8);
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