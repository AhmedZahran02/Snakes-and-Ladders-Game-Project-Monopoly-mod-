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
	pOut->PrintMessage("Click on cell to cut :");
	// Read the CardCell parameter
	cardPosition = pIn->GetCellClicked();
	//Validation
	if (cardPosition.IsValidCell() == false)
	{
		pGrid->PrintErrorMessage("Invalid Cell ! ");
		return;
	}
	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void CutCardAction::Execute()
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	//pGrid->;
	if (true)
	{
		//pGrid->SetClipboard();
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
