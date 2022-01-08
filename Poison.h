#pragma once
#include "Attack.h"
class Poison :
	public Attack
{
private:
	// [Action Parameters]
public:
	Poison(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters();

	static  void Execute(Grid* pGrid);

	virtual ~Poison(); // A Virtual Destructor
};

