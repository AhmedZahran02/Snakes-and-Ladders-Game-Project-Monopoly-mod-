#include "Attack.h"
#include "Grid.h"

Attack::Attack(ApplicationManager* pApp,int attacknum) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
	Remainingattacks = 2; //set attacks remained =2
	attacknumber = attacknum;
}

Attack::~Attack()
{
}

void Attack::ReadActionParameters()
{
}


// Execute the action
void Attack::Execute(Grid* pGrid, Player* pPlayer)
{
	if (Remainingattacks>0)
	{
		Remainingattacks--;
	}
	else
	{
		pGrid->PrintErrorMessage("you have no more special attacks");
	}
}
