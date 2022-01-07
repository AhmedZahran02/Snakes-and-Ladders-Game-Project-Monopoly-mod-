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
		pOut->PrintMessage("click on cell to paste the card to it ........");
		pastePosition = pIn->GetCellClicked(); // Read the CardCell parameter
	} while (pastePosition.IsValidCell() == false || pastePosition.GetCellNum() == 1 || pastePosition.GetCellNum() == 99 || pGrid->GetGameObject(pastePosition) != NULL);

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
		pCard->SetPosition(pastePosition);
		pGrid->AddObjectToCell(pCard);
		//update interface
		pGrid->UpdateInterface();
		pGrid->PrintErrorMessage("Successfully Card " + to_string(pCard->GetCardNumber()) + " was pasted ,click to continue!");
	}
	else
	{
		pGrid->PrintErrorMessage("error cannot paste ,No card in clipboard ,click to continue!");
		return;
	}

	
}

PasteCardAction::~PasteCardAction()
{
}
