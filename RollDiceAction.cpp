#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"
#include "Card.h"
#include "CardEight.h"
#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	Grid* pGrid = pManager->GetGrid();
	if (pGrid->GetEndGame()) {
		pGrid->GetOutput()->PrintMessage("game ended !");
		int x, y;
		pGrid->GetInput()->GetPointClicked(x, y);
		pManager->ExecuteAction(EXITT);
	}
	else {
		// -- If not ended, do the following --:
		Output* pOut = pGrid->GetOutput();
		Player* pPlayer = pGrid->GetCurrentPlayer();
		int playerNum = pPlayer->GetPlayerNum();
		Cell* pCell = pPlayer->GetCell();
		GameObject* pObj = pCell->GetGameObject();
		CardEight* pCardEight = dynamic_cast<CardEight*>(pObj);
		if (pCardEight && pCardEight->isJailed(playerNum)) {
			pCardEight->DecrementRemDays(playerNum);
			if (pCardEight->GetRemDays(playerNum) == 0) {
				pCardEight->free(playerNum);
				pOut->PrintMessage("You are now free from next turn!");
			}
			else {
				pOut->PrintMessage("You are locked in prison! " + to_string(pCardEight->GetRemDays(playerNum)) + " turns remaining.");
			}			
			pGrid->AdvanceCurrentPlayer();
			pGrid->UpdateInterface();
		}
		else {
			// 2- Generate a random number from 1 to 6 --> This step is done for you
			srand((int)time(NULL)); // time is for different seed each run
			int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
			pGrid->GetOutput()->PrintMessage("Rolled Dice " + to_string(diceNumber) + "Click to continue");
			int x, y;
			pGrid->GetInput()->GetPointClicked(x, y);
			// 3- Get the "current" player from pGrid



			// 4- Move the currentPlayer using function Move of class player
			pPlayer->Move(pGrid, diceNumber);
			// 5- Advance the current player number of pGrid
			pGrid->AdvanceCurrentPlayer();


			pGrid->UpdateInterface();
		}
	}
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

RollDiceAction::~RollDiceAction()
{
}
