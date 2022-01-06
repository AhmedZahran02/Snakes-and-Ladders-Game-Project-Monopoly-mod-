#include "CardNineToEleven.h"

CardNineToEleven::CardNineToEleven(const CellPosition& pos,int cardnum) : Card(pos) 
{
	cardNumber = cardnum; // set the inherited cardNumber data member with the card number 
}
void CardNineToEleven::ReadCardParameters(Grid* pGrid)
{
}

void CardNineToEleven::Apply(Grid* pGrid, Player* pPlayer)
{
}

void CardNineToEleven::Save(ofstream& outFile, int Type)
{

}
