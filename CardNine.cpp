#include "CardNine.h"

Player* CardNine::card9owner;

CardNine::CardNine(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number (1 here)
	card9owner = NULL;
}

void CardNine::setowner(Player* p)
{
	card9owner = p;
}

CardNine::~CardNine(void)
{
}

void CardNine::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read an Integer from the user using the Input class and set the parameters with it
	pOut->PrintMessage("New Card 9: Enter its Price ...");
	CardPrice = pIn->GetInteger(pOut);
	pOut->PrintMessage("Card 9: Enter its Fees ...");
	Fees = pIn->GetInteger(pOut);

	// [ Note ]:
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (card9owner ==NULL)
	{
		pOut->PrintMessage("Do you want to buy those cells with cardnumber 9    1-yes   2-no");
		int choise = pIn->GetInteger(pOut);
		if (choise == 2)
		{
			return;
		}
		if (choise == 1)
		{
			if (pPlayer->GetWallet() >= CardPrice)
			{
				setowner(pPlayer);
				card9owner->SetWallet(card9owner->GetWallet() - CardPrice);
				// apply owner for all cards not this only -> static
				
			}
			else
			{
				pGrid->PrintErrorMessage("you donot have enough money in your wallet");
				return;
			}
		}
	}
	else
	{
			pPlayer->SetWallet(pPlayer->GetWallet() - Fees);
			card9owner->SetWallet(card9owner->GetWallet() + Fees);
			return;
	}
	
}

