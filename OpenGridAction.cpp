#include "OpenGridAction.h"
#include "Grid.h"
#include <fstream>
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"

OpenGridAction::OpenGridAction(ApplicationManager* pApp)
	:Action(pApp)
{

}

OpenGridAction::~OpenGridAction()
{

}

void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please enter filename: ");
	fileName = pIn->GetString(pOut);

	pOut->ClearStatusBar();
}

void OpenGridAction::Execute()
{
	ReadActionParameters();
	ifstream inFile(fileName);

	Grid* pGrid = pManager->GetGrid();
	int ladderCount, snakeCount, cardCount;

	inFile >> ladderCount;
	Ladder* pLadder;
	for (int i = 0; i < ladderCount; i++) {
		pLadder->Open(inFile);
		pGrid->AddObjectToCell(pLadder);
	}

	inFile >> snakeCount;
	Snake* pSnake;
	for (int i = 0; i < snakeCount; i++) {
		pSnake->Open(inFile);
		pGrid->AddObjectToCell(pSnake);
	}

	inFile >> cardCount;
	Card* pCard;
	for (int i = 0; i < cardCount; i++) {
		pCard;
	}
}