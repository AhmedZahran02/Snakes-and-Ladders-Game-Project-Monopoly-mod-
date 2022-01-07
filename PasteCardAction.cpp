#include "PasteCardAction.h"
#include "CutCardAction.h"
#include "CopyCardAction.h"
#include "AddCardAction.h"
#include "ApplicationManager.h"
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
	Card *cCard = pGrid->GetClipboard();
	cardnum = cCard->GetCardNumber();
	if (cCard)
	{
		Card* pCard = NULL;
		switch (cardnum) //creating new card depending on card number taken from clipboard 
		{
		case 1:
			pCard = new CardOne(*(dynamic_cast<CardOne*>(cCard)));
			break;
		case 2:
			pCard = new CardTwo(*(dynamic_cast<CardTwo*>(cCard)));
			break;
		case 3:
			pCard = new CardThree(*(dynamic_cast<CardThree*>(cCard)));
			break;
		case 4:
			pCard = new CardFour(*(dynamic_cast<CardFour*>(cCard)));
			break;
		case 5:
			pCard = new CardFive(*(dynamic_cast<CardFive*>(cCard)));
			break;
		case 6:
			pCard = new CardSix(*(dynamic_cast<CardSix*>(cCard)));
			break;
		case 7:
			pCard = new CardSeven(*(dynamic_cast<CardSeven*>(cCard)));
			break;
		case 8:
			pCard = new CardEight(*(dynamic_cast<CardEight*>(cCard)));
			break;
		case 9:
			pCard = new CardNine(*(dynamic_cast<CardNine*>(cCard)));
			break;
		case 10:
			pCard = new CardTen(*(dynamic_cast<CardTen*>(cCard)));
			break;
		case 11:
			pCard = new CardEleven(*(dynamic_cast<CardEleven*>(cCard)));
			break;
		case 12:
			pCard = new CardTwelve(*(dynamic_cast<CardTwelve*>(cCard)));
			break;
		}
		pCard->SetPosition(pastePosition); //changing position to new paste position
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
		pCard->Save(outFile, 2); //writing in save file which is .txt
								 // number 2 representing cards
}


PasteCardAction::~PasteCardAction()
{
}
