#include "InputDiceValueAction.h"
#include "Grid.h"
#include "Player.h"

InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp)
	: Action(pApp)
{

}

void InputDiceValueAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	do
	{
		pOut->PrintMessage("Please enter a dice value between 1 and 6 (inclusive): ");
		inputDiceValue = pIn->GetInteger(pOut);
	} while (inputDiceValue < 1 || inputDiceValue > 6);
}

void InputDiceValueAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (pGrid->GetEndGame()) {
		pGrid->GetOutput()->PrintMessage("game ended !");
		int x, y;
		pGrid->GetInput()->GetPointClicked(x, y);
		pManager->ExecuteAction(EXITT);
	}
	else {
		Player* pPlayer = pGrid->GetCurrentPlayer();
		// 4- Move the currentPlayer using function Move of class player
		pPlayer->Move(pGrid, inputDiceValue);
		// 5- Advance the current player number of pGrid
		pGrid->AdvanceCurrentPlayer();
	}
}

InputDiceValueAction::~InputDiceValueAction()
{

}