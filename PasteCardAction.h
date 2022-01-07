#pragma once
#include "Action.h"

class PasteCardAction :
	public Action
{
	// [Action Parameters]
	CellPosition pastePosition; //  cell position of the card

public:

	PasteCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CutCardAction parameters (cardNumber, cardPosition)

	virtual void Execute(); // Applies the effect of paste action on the passed Player
	                                                  // by pasting card from clipboard and leaving a copy in clipboard

	virtual ~PasteCardAction(); // Virtual Destructor
};
