#include "NewGameAction.h"
#include "Grid.h"
#include "Player.h"

NewGameAction::NewGameAction(ApplicationManager* pApp)
	: Action(pApp)
{

}

void NewGameAction::ReadActionParameters()
{

}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->SetEndGame(0);
	CellPosition start(8, 0);
	for (int i = 0; i < 4; i++) {
		Player* pPlayer = pGrid->GetCurrentPlayer();
		pGrid->UpdatePlayerCell(pPlayer, start);
		pPlayer->SetWallet(100);
		pPlayer->SetStepCount(1);
		pPlayer->SetTurnCount(0);
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->ReSetCurrentPlayerNum();
}

NewGameAction::~NewGameAction()
{

}