#include "CutCardAction.h"
#include "ApplicationManager.h"
#include "Card.h"
#include "GameObject.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void CutCardAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	do {
		pOut->PrintMessage("click on cell with card to cut .......");
		cardPosition=pIn->GetCellClicked();
	} while (cardPosition.IsValidCell() != true);

	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void CutCardAction::Execute()
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Card* CardinCell= pGrid->GetGameObject(cardPosition); //get card object in the cell
	if (CardinCell)
	{
		pGrid->SetClipboard(CardinCell);
		pGrid->RemoveObjectFromCell(cardPosition);
		//update interface
		pGrid->UpdateInterface();
		pGrid->PrintErrorMessage("Successfully Card "+to_string(CardinCell->GetCardNumber())+" was cut ,click to continue!");
	}
	else
	{
		pGrid->PrintErrorMessage("error cannot cut ,No Card was found ,click to continue!");
		return;
	}

	
}

CutCardAction::~CutCardAction()
{
}
