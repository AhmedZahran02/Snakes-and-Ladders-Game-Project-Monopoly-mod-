#pragma once
#include "Action.h"

class PasteCardAction :
	public Action
{
	// [Action Parameters]
	CellPosition cardPosition; //  cell position of the card

public:

	PasteCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CutCardAction parameters (cardNumber, cardPosition)

	virtual void Execute();

	virtual ~PasteCardAction(); // Virtual Destructor
};
