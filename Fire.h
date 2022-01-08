#pragma once
#include "Attack.h"
class Fire :
    public Attack
{
public:
    Fire(ApplicationManager* pApp);

    static void Execute(Grid* pGrid);

    virtual ~Fire();
};

