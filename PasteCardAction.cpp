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
	} while (pastePosition.IsValidCell() == false || pastePosition.GetCellNum() == 1 || pastePosition.GetCellNum() == 99 || pGrid->GetGameObject(pastePosition) != NULL); //checking cases where canot paste the card

	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void PasteCardAction::Execute()
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	pCard = pGrid->GetClipboard();
	if (pCard)
	{
		pCard->SetPosition(pastePosition); //setting position to be pasted on
		pGrid->AddObjectToCell(pCard); //adding card to cell 
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

void PasteCardAction::Save(ofstream& outFile, int Type)
{
	pCard->Save(outFile,2);
}


PasteCardAction::~PasteCardAction()
{
}
