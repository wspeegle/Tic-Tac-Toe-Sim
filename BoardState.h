#ifndef BOARDSTATE_H
#define BOARDSTATE_H

#include <string>

#ifndef BOARD_CONSTANTS
#define BOARD_CONSTANTS 1
const int BOARD_SIZE = 9;
const int GAME_IN_PROGRESS = 0;
const int X_WIN = 1;
const int O_WIN = 2;
const int GAME_DRAW = 3;
const int MAX_SUM = 511;
#endif

class BoardState{
  private:
	int xCount;
	int oCount;
	int xSum;
	int oSum;
	int outcome;
	int Turn;
  public:
	BoardState(const std::string);
	BoardState(BoardState*);	


	BoardState* clone();
	int getXSum();
	int getOSum();
	int getTurn();
	int getXCount();
	int getOCount();
	int getOutcome();
	void addXCount();
	void addOCount();
	void setXSum(int);
	void setOSum(int);
	void setXCount(int);
	void setOCount(int);
	void setOutcome(int);
	void print();	
};
#endif
