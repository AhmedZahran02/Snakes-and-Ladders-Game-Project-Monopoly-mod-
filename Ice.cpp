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
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Player* player = pGrid->GetCurrentPlayer();
	int playernum = player->GetPlayerNum();
	int playernumtoice;
	do {
		pOut->PrintMessage("Choose a player to prevent from rolling the next turn");
		playernumtoice = pIn->GetInteger(pOut);
	} while (playernumtoice < 0 || playernumtoice > 3 || playernumtoice == playernum);
	
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		pGrid->AdvanceCurrentPlayer();
		if (pGrid->GetCurrentPlayer()->GetPlayerNum()==playernumtoice)
		{
			pGrid->GetCurrentPlayer()->SetCardFourEffect(true);
		}
	}
}
