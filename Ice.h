#pragma once
#include "Attack.h"
class Ice :
    public Attack
{
private:
	// [Action Parameters]
public:
	Ice(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters();

	static void Execute(Grid* pGrid);

	virtual ~Ice(); // A Virtual Destructor
};

