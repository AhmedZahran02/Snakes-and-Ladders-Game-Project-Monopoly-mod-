#include "Lightning.h"

Lightning::Lightning(ApplicationManager* pApp):Attack(pApp)
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
void Lightning::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	

}
