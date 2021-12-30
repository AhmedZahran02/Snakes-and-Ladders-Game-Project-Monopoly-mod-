#include "CardNineToEleven.h"

CardNineToEleven::CardNineToEleven(const CellPosition& pos,int cardnum) : Card(pos) // set the cell position of the card
{
	cardNumber = cardnum; // set the inherited cardNumber data member with the card number (1 here)
	owner = NULL;
}

CardNineToEleven::~CardNineToEleven(void)
{
}

void CardNineToEleven::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read an Integer from the user using the Input class and set the parameters with it
	pOut->PrintMessage("New Card "+to_string(cardNumber)+": Enter its Price ...");
	CardPrice = pIn->GetInteger(pOut);
	pOut->PrintMessage("Card " + to_string(cardNumber) + ": Enter its Fees ...");
	Fees = pIn->GetInteger(pOut);

	// [ Note ]:
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardNineToEleven::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (owner==NULL)
	{
		pOut->PrintMessage("Do you want to buy this sell    1-yes   2-no");
		int choise = pIn->GetInteger(pOut);
		if (choise==2)
		{
			return;
		}
		if (choise ==1)
		{
			if (pPlayer->GetWallet() >= CardPrice)
			{
				owner = pPlayer;
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
		if (pPlayer->GetCell()->HasCard()->GetCardNumber() == cardNumber)
		{
			pPlayer->SetWallet(pPlayer->GetWallet() - Fees);
			owner->SetWallet(owner->GetWallet() + Fees);
			return;
		}
	}
	
}

