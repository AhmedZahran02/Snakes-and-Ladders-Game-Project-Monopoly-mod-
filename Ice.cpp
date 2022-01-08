#include "Ice.h"
#include "Player.h"

Ice::Ice(ApplicationManager* pApp) : Attack(pApp)
{

}

void Ice::ReadActionParameters()
{

}

Ice::~Ice()
{
}

// Execute the action
void Ice::Execute(Grid* pGrid)
{
	for (int i = 0; i < MaxPlayerCount - 1; i++)
	{
		pGrid->AdvanceCurrentPlayer();
		pGrid->GetCurrentPlayer()->SetWallet(pGrid->GetCurrentPlayer()->GetWallet() - 20);
	}
	pGrid->AdvanceCurrentPlayer();
}
