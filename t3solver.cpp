#include "TreeNode.h"
#include "BoardState.h"
#include "TreeMaker.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
int main(int argc, char* argv[])
{

std::ifstream inputFile(argv[1]);
std::string BOARD_INPUT;
while(std::getline(inputFile, BOARD_INPUT))
{
	clock_t time = clock();
	//Gather file info
	std::istringstream iss(BOARD_INPUT);
	std::string BOARD_LINE;
	iss >> BOARD_LINE;
	//Create BoardState from file lines
	BoardState* BOARD_ROOT = new BoardState(BOARD_LINE);
	TreeNode* tnode = new TreeNode(BOARD_ROOT);
	TreeMaker* tree = new TreeMaker(tnode);
	
	std::cout << "The current board is: " << std::endl;
	BOARD_ROOT -> print();
	int boardTurn = BOARD_ROOT -> getTurn();
	if(boardTurn == -1)
	{
		
		std::cout << "This is an invalid board state!" << std::endl;
	}
	else{
	tree->buildTree(tnode);
	int size = tree -> getSize();
	
	time = clock() -time;
	int ms = double(time)/CLOCKS_PER_SEC * 1000;	
	std::cout << size << " nodes were created for this starting board in " << ms << " ms" << std::endl;
		printf("PreOrder notation: \n");
	tree->preOrder(tnode);
	

	printf("LevelOrder notation: \n");
	tree->levelOrder(tnode);
	

	printf("PostOrder notation: \n");
	tree->postOrder(tnode);
	

	printf("Terminal Path:\n");
	tree->terminalPath(tnode);


	}

	
}
}