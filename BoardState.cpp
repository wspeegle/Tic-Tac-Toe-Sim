#include "BoardState.h"
#include <stdio.h>
#include <math.h>
#include <array>
#include <iostream>
#include <cstring>

//accepts a boardState of the form *****XX**0 and creates a boardState object
BoardState::BoardState(const std::string boardString){
	
	//convert string to an array of chars
	
	char boardPosition[9];
	std::memcpy(boardPosition, boardString.c_str(), boardString.size());
	xSum = 0;
	oSum = 0;
	xCount = 0;
	oCount = 0;
	
	for(int i=0; i < 10; i++)
	{
		if(boardPosition[i] == 'x' || boardPosition[i] == 'X')
		{
			xSum = xSum + pow(2, i);
			xCount = xCount + 1;
		}
		if(boardPosition[i] == 'o' || boardPosition[i] == 'O')
		{
			oSum = oSum + pow(2, i);
			oCount = oCount + 1;
		}
	}
		if(oCount > xCount || xCount >= oCount + 2)
		{
			Turn = -1;
		}
		else if(xCount == (oCount+1))
		{
			Turn = 0;
		}
		else
			Turn = 1;
	
};

//This constructor is used for cloning
BoardState::BoardState(BoardState* b)
{
	xSum = b->getXSum();
	oSum = b->getOSum();
	xCount = b->getXCount();
	oCount = b->getOCount();
	Turn = b->getTurn();
}

BoardState* BoardState::clone()
{
  return new BoardState(*this);
};

// GETTERS AND SETTERS

int BoardState::getXSum() {
	return xSum; 
}

int BoardState::getOSum()  {
	return oSum;
}

int BoardState::getXCount()  {
	return xCount;
}

int BoardState::getOCount(){
	return oCount;
}

int BoardState::getOutcome()
{
	//Here we can use the Bitwise AND in order to check if there is a winning sum, since we cannot simply check the sums (in cases of extra
	//	x's or o'). 
	if((xSum & 7) == 7 || (xSum & 56) == 56 || (xSum & 448) == 448 || (xSum & 73) == 73 || (xSum & 146) == 146 || (xSum & 292) == 292 || (xSum & 273) == 273 || (xSum & 84) == 84)
	{
		setOutcome(X_WIN);
		return outcome;
	}
	else if((oSum & 7) == 7 || (oSum & 56) == 56 || (oSum & 448) == 448 || (oSum & 73) == 73 || (oSum & 146) == 146 || (oSum & 292) == 292 || (oSum & 273) == 273 || (oSum & 84) == 84)
	{
		setOutcome(O_WIN);
		return outcome;
	}
	else if(xSum+oSum == 511)
	{
		setOutcome(GAME_DRAW);
		return outcome;
	}
	else
		setOutcome(GAME_IN_PROGRESS);
	
	
	return outcome;
}

int BoardState::getTurn()
{
//Turn: -1 indicates invalid board
// 	  0 indicates X has gone and it is O's turn
//	  1 indicates O has gone and it is X's turn
	if(oCount > xCount || xCount >= oCount + 2)
		{
			Turn = -1;
		}
		else if(xCount == (oCount+1))
		{
			Turn = 0;
		}
		else
			Turn = 1;
	return Turn;
}

void BoardState::setXSum(int x)
{
	xSum = x;
}

void BoardState::setOSum(int o)
{
	oSum = o;
}

void BoardState::setXCount(int x)
{
	xCount = x;
}

void BoardState::addXCount()
{
	xCount++;
}
void BoardState::addOCount()
{
	oCount++;
}

void BoardState::setOCount(int o)
{
	oCount  = o;
}
void BoardState::setOutcome(int o)
{
	outcome = o;
}

void BoardState::print()
{
	int tempXSum = getXSum();
 	int tempOSum = getOSum();
	std::array<char, BOARD_SIZE> out;
	for(int i=0; i<BOARD_SIZE; i++)
	{
	  out[i] = '*';
	}
	int lgResult;
	int powResult;
	
	while(tempXSum != 0)
	{
	  lgResult = floor(log2(tempXSum));
	  out[lgResult] = 'X';
	  powResult = (int) pow(2, lgResult);
	  tempXSum -= powResult;
	}
	
	while(tempOSum != 0)
	{	
	  lgResult = floor(log2(tempOSum));	
	  out[lgResult] = 'O';	
	  powResult = (int) pow(2, lgResult);
	  tempOSum -= powResult;
	}
	
	for(int i=0; i <9; i++)
		std::cout << out[i];

	std::cout << std::endl;	
}
