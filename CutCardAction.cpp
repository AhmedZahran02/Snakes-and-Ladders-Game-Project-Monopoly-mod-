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
		cardPosition=new Cell(pIn->GetCellClicked());
	} while (cardPosition->GetCellPosition().IsValidCell() != true);

	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void CutCardAction::Execute()
{
	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	GameObject* pCard= cardPosition->GetGameObject(); //get card object in the cell
	int x, y;
	if (dynamic_cast<Card*>(pCard))
	{
		pGrid->SetClipboard((Card*)pCard);
		pGrid->RemoveObjectFromCell(cardPosition->GetCellPosition());
	}
	else
	{
		pGrid->PrintErrorMessage("error cannot cut");
		pGrid->GetInput()->GetPointClicked(x, y);
		return;
	}

	//update interface
	pGrid->UpdateInterface();
}

CutCardAction::~CutCardAction()
{
	delete cardPosition;
}
