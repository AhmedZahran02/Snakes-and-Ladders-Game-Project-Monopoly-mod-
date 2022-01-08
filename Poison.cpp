#include "Poison.h"
#include "Poison.h"
#include "Player.h"

Poison::Poison(ApplicationManager* pApp) : Attack(pApp)
{

}

void Poison::ReadActionParameters()
{

	
}

Poison::~Poison()
{
}

// Execute the action
  void Poison::Execute(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int playernum = pGrid->GetCurrentPlayer()->GetPlayerNum();
	int playernumtoPoison;
	do {
		pOut->PrintMessage("Choose a player to poison. For 5 turns, 1 will be deducted from his dice roll");
		playernumtoPoison = pIn->GetInteger(pOut);
	} while (playernumtoPoison < 0 || playernumtoPoison > 3 || playernumtoPoison == playernum);
	do {
		pOut->PrintMessage("Choose a player to poison. For 5 turns, 1 will be deducted from his dice roll");
		playernumtoPoison = pIn->GetInteger(pOut);
	} while (playernumtoPoison < 0 || playernumtoPoison > 3 || playernumtoPoison == playernum);

	
}
