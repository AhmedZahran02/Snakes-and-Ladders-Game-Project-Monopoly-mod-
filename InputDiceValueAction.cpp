#include "InputDiceValueAction.h"
#include "Grid.h"

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
	} while (inputDiceValue < 1 && inputDiceValue > 6);
}

void InputDiceValueAction::Execute()
{

}