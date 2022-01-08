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
	pGrid->PrintErrorMessage("Choose a player to prevent from rolling the next turn");
	int playernumtoice =pGrid->GetInput()->GetInteger(pGrid->GetOutput());
	Player* player = pGrid->GetCurrentPlayer();
	int playernum = player->GetPlayerNum();
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		pGrid->AdvanceCurrentPlayer();
		if (pGrid->GetCurrentPlayer()->GetPlayerNum()==playernumtoice && pGrid->GetCurrentPlayer()->GetPlayerNum() != playernum)
		{
			pGrid->GetCurrentPlayer()->SetCardFourEffect(true);
		}
	}
}
