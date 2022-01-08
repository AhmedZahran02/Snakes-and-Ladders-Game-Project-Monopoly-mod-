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
	ifstream inFile(fileName+".txt",ios::in);
	Grid* pGrid = pManager->GetGrid();
	pGrid->RemoveAllObjects();
	pGrid->RestartAllPlayers();
	pGrid->SetClipboard(NULL);
	CellPosition end;
	CellPosition start;
	int ladderCount, snakeCount, cardCount;
	
	if (inFile.is_open())
	{
		inFile >> ladderCount;
		for (int i = 0; i < ladderCount; i++) {
			Ladder* pLadder = new Ladder(start, end);
			pLadder->Open(inFile);
			if (pLadder->IsValid() && !pGrid->IsOverLapping(pLadder))
				pGrid->AddObjectToCell(pLadder);
		}
	
		inFile >> snakeCount;
		for (int i = 0; i < snakeCount; i++) {
			Snake* pSnake = new Snake(end, start);
			pSnake->Open(inFile);
			if (pSnake->IsValid() && !pGrid->IsOverLapping(pSnake))
				pGrid->AddObjectToCell(pSnake);
		}
	
		inFile >> cardCount;

	
		int cardNumber;
		for (int i = 0; i < cardCount; i++) {
			inFile >> cardNumber;
			switch (cardNumber)
			{
			case 1:
			{
				CardOne* pCardOne = new CardOne(start);
				pCardOne->Open(inFile);
				if (pCardOne->IsValid() && !pGrid->IsOverLapping(pCardOne))
					pGrid->AddObjectToCell(pCardOne);
			}
			break;
			case 2:
			{
				CardTwo* pCardTwo = new CardTwo(start);
				pCardTwo->Open(inFile);
				if (pCardTwo->IsValid() && !pGrid->IsOverLapping(pCardTwo))
					pGrid->AddObjectToCell(pCardTwo);
			}
			break;
			case 3:
			{
				CardThree* pCardThree = new CardThree(start);
				pCardThree->Open(inFile);
				if (pCardThree->IsValid() && !pGrid->IsOverLapping(pCardThree))
					pGrid->AddObjectToCell(pCardThree);
			}
			break;
			case 4:
			{
				CardFour* pCardFour = new CardFour(start);
				pCardFour->Open(inFile);
				if (pCardFour->IsValid() && !pGrid->IsOverLapping(pCardFour))
					pGrid->AddObjectToCell(pCardFour);
			}
			break;
			case 5:
			{
				CardFive* pCardFive = new CardFive(start);
				pCardFive->Open(inFile);
				if (pCardFive->IsValid() && !pGrid->IsOverLapping(pCardFive))
					pGrid->AddObjectToCell(pCardFive);
			}
			break;
			case 6:
			{
				CardSix* pCardSix = new CardSix(start);
				pCardSix->Open(inFile);
				if (pCardSix->IsValid() && !pGrid->IsOverLapping(pCardSix))
					pGrid->AddObjectToCell(pCardSix);
			}
			break;
			case 7:
			{
				CardSeven * pCardSeven = new CardSeven(start);
				pCardSeven->Open(inFile);
				if (pCardSeven->IsValid() && !pGrid->IsOverLapping(pCardSeven))
					pGrid->AddObjectToCell(pCardSeven);
			}
				break;
			case 8:
			{
				CardEight* pCardEight = new CardEight(start);
				pCardEight->Open(inFile);
				if (pCardEight->IsValid() && !pGrid->IsOverLapping(pCardEight))
					pGrid->AddObjectToCell(pCardEight);
			}
				break;
			case 9:
			{
				CardNine* pCardNine = new CardNine(start);
				pCardNine->Open(inFile);
				if (pCardNine->IsValid() && !pGrid->IsOverLapping(pCardNine))
					pGrid->AddObjectToCell(pCardNine);
			}
				break;
			case 10:
			{
				CardTen* pCardTen = new CardTen(start);
				pCardTen->Open(inFile);
				if (pCardTen->IsValid() && !pGrid->IsOverLapping(pCardTen))
					pGrid->AddObjectToCell(pCardTen);
			}
				break;
			case 11:
			{
				CardEleven* pCardEleven = new CardEleven(start);
				pCardEleven->Open(inFile);
				if (pCardEleven->IsValid() && !pGrid->IsOverLapping(pCardEleven))
					pGrid->AddObjectToCell(pCardEleven);
			}
				break;
			case 12:
			{
				CardTwelve* pCardTwelve = new CardTwelve(start);
				pCardTwelve->Open(inFile);
				if (pCardTwelve->IsValid() && !pGrid->IsOverLapping(pCardTwelve))
					pGrid->AddObjectToCell(pCardTwelve);
			}
				break;
			}
		}
		inFile.close();
	}
	pGrid->UpdateInterface();
}