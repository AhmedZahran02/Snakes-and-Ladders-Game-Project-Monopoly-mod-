#include "SaveGridAction.h"
#include "Grid.h"
#include <fstream>

SaveGridAction::SaveGridAction(ApplicationManager* pApp)
	:Action(pApp)
{

}

SaveGridAction::~SaveGridAction()
{

}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Please enter the filename: ");
	fileName = pIn->GetString(pOut);

	pOut->ClearStatusBar();
}

void SaveGridAction::Execute()
{
	ReadActionParameters();
	ofstream outFile(fileName);

	Grid* pGrid = pManager->GetGrid();
	pGrid->SaveAll(outFile, 0);
	pGrid->SaveAll(outFile, 1);
	pGrid->SaveAll(outFile, 2);
	
	outFile.close();
}