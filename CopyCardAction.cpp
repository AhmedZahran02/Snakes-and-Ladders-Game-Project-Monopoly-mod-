#include "CopyCardAction.h"
#include "ApplicationManager.h"
#include "Card.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void CopyCardAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int x, y;
	do {
		pOut->PrintMessage("click on cell with card to copy");
		cardPosition = pIn->GetCellClicked(); // Read the CardCell parameter
	} while (cardPosition.IsValidCell() != true);

	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void CopyCardAction::Execute()
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Card* pCard = pGrid->GetClipboard();
	if (pCard)
	{
		pGrid->SetClipboard(pCard);
	}
	else
	{
		pGrid->PrintErrorMessage("error cannot copy");
		return;
	}

	//update interface
	pGrid->UpdateInterface();
}

CopyCardAction::~CopyCardAction()
{
}
