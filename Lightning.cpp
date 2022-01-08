#include "Lightning.h"
#include "Player.h"

Lightning::Lightning(ApplicationManager* pApp):Attack(pApp,4)
{
	done = false;
}

Lightning::~Lightning()
{
}

void Lightning::ReadActionParameters()
{
}


// Execute the action
void Lightning::Execute(Grid* pGrid, Player* pPlayer)
{
	pPlayer->
	
}
