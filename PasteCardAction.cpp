#include "PasteCardAction.h"
#include "ApplicationManager.h"
#include "Card.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void PasteCardAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int x, y;
	do {
		pOut->PrintMessage("click on cell with card to paste");
		cardPosition = pIn->GetCellClicked(); // Read the CardCell parameter
	} while (cardPosition.IsValidCell() != true);

	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void PasteCardAction::Execute()
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Card* pCard = pGrid->GetClipboard();
	if (pCard)
	{
		pGrid->GetOutput()->DrawCell(pCard->GetPosition(),pCard->GetCardNumber());
	}
	else
	{
		pGrid->PrintErrorMessage("error cannot paste");
		return;
	}

	//update interface
	pGrid->UpdateInterface();
}

PasteCardAction::~PasteCardAction()
{
}
