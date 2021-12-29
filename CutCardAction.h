#pragma once

#include "Action.h"

class CutCardAction : public Action
{
	// [Action Parameters]
	CellPosition cardPosition; //  cell position of the card

public:

	CutCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CutCardAction parameters (cardNumber, cardPosition)

	virtual void Execute();

	virtual ~CutCardAction(); // Virtual Destructor
};
