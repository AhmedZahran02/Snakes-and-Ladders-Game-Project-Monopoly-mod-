#include "OpenGridAction.h"
#include "Grid.h"
#include <fstream>
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"

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
	ifstream inFile(fileName+".txt");
	Grid* pGrid = pManager->GetGrid();
	pGrid->RemoveAllObjects();
	CellPosition end(0, 0);
	CellPosition start(1, 0);
	int ladderCount, snakeCount, cardCount;

	inFile >> ladderCount;
	Ladder* pLadder = new Ladder(start, end);
	for (int i = 0; i < ladderCount; i++) {
		pLadder->Open(inFile);
		pGrid->AddObjectToCell(pLadder);
	}

	inFile >> snakeCount;
	Snake* pSnake = new Snake(end, start);
	for (int i = 0; i < snakeCount; i++) {
		pSnake->Open(inFile);
		pGrid->AddObjectToCell(pSnake);
	}

	inFile >> cardCount;
	Card* pCard = new Card(start);
	CardOne * pCardOne = new CardOne(start);
	CardTwo * pCardTwo = new CardTwo(start);
	CardThree * pCardThree = new CardThree(start);
	CardFour* pCardFour = new CardFour(start);
	CardFive* pCardFive = new CardFive(start);
	CardSix* pCardSix = new CardSix(start);
	CardSeven* pCardSeven = new CardSeven(start);
	CardEight* pCardEight = new CardEight(start);
	CardNine* pCardNine = new CardNine(start);
	CardTen* pCardTen = new CardTen(start);
	CardEleven* pCardEleven = new CardEleven(start);
	CardTwelve* pCardTwelve = new CardTwelve(start);
	for (int i = 0; i < cardCount; i++) {
		int cardNumber;
		inFile >> cardNumber;
		switch (cardNumber)
		{
		case 1:
			pCardOne->Open(inFile);
			pGrid->AddObjectToCell(pCardOne);
			break;
		case 2:
			pCardTwo->Open(inFile);
			pGrid->AddObjectToCell(pCardTwo);
			break;
		case 3:
			pCardThree->Open(inFile);
			pGrid->AddObjectToCell(pCardThree);
			break;
		case 4:
			pCardFour->Open(inFile);
			pGrid->AddObjectToCell(pCardFour);
			break;
		case 5:
			pCardFive->Open(inFile);
			pGrid->AddObjectToCell(pCardFive);
			break;
		case 6:
			pCardSix->Open(inFile);
			pGrid->AddObjectToCell(pCardSix);
			break;
		case 7:
			pCardSeven->Open(inFile);
			pGrid->AddObjectToCell(pCardSeven);
			break;
		case 8:
			pCardEight->Open(inFile);
			pGrid->AddObjectToCell(pCardEight);
			break;
		case 9:
			pCardNine->Open(inFile);
			pGrid->AddObjectToCell(pCardNine);
			break;
		case 10:
			pCardTen->Open(inFile);
			pGrid->AddObjectToCell(pCardTen);
			break;
		case 11:
			pCardEleven->Open(inFile);
			pGrid->AddObjectToCell(pCardEleven);
			break;
		case 12:
			pCardTwelve->Open(inFile);
			pGrid->AddObjectToCell(pCardTwelve);
			break;
		}
	}
}