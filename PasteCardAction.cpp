#include "PasteCardAction.h"
#include "CutCardAction.h"
#include "CopyCardAction.h"
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
	do {
		pOut->PrintMessage("click on cell to paste in it");
		pastePosition = pIn->GetCellClicked(); // Read the CardCell parameter
	} while (pastePosition.IsValidCell() == false || pastePosition.GetCellNum() == 1 || pastePosition.GetCellNum() == 99);

	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void PasteCardAction::Execute()
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	int x, y;
	Grid* pGrid = pManager->GetGrid();
	Card* pCard = pGrid->GetClipboard();
	if (pCard)
	{
		pCard->SetPosition(pastePosition);
		pGrid->AddObjectToCell(pCard);
		pGrid->SetClipboard(NULL);
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
