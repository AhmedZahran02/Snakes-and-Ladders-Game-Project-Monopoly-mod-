#include "Attack.h"
#include "Grid.h"

Attack::Attack(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

Attack::~Attack()
{
}

void ReadActionParameters(){}

// Execute the action
void Attack::Execute(Grid* pGrid, Player* pPlayer)
{
}
