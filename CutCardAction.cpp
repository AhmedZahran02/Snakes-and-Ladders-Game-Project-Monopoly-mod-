#include "CutCardAction.h"
#include "ApplicationManager.h"
#include "Card.h"

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
	int x, y;
	do {
		pOut->PrintMessage("click on cell with card to cut");
		pIn->GetPointClicked(x, y);
		cardPosition = pIn->GetCellClicked(); // Read the CardCell parameter
	} while (cardPosition.IsValidCell() != true);

	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void CutCardAction::Execute()
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Card* pCard = pGrid->GetClipboard();
	if (pCard)
	{
		pGrid->SetClipboard(pCard);
		pGrid->RemoveObjectFromCell(cardPosition);
	}
	else
	{
		pGrid->PrintErrorMessage("error cannot cut");
		return;
	}

	// Here, the Card/CoinSet is cut and added to the Clipboard, so we finished executing the CutCardOrCoinsAction
	pGrid->UpdateInterface();
}

CutCardAction::~CutCardAction()
{
}
