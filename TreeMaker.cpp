#include "TreeMaker.h"
#include <array>
#include <vector>
#include <queue>
#include <iostream>
#include <math.h>
#include<stdio.h>

TreeMaker::TreeMaker()
:size(0),
root(NULL)
{};

TreeMaker::TreeMaker(TreeNode* n)
:size(1),
root(n)
{};

void TreeMaker::setRoot(TreeNode* r)
{
	root = r;
}

void TreeMaker::setSize(int s)
{
	size = s;
}

TreeNode* TreeMaker::getRoot() const
{
	return root;
}

int TreeMaker::getSize() const
{
	return size;
}

void TreeMaker::insert(TreeNode* p, TreeNode* c)
{
	p->addChild(c);
	c->setParent(p);
	size++;
}

void TreeMaker::buildTree(TreeNode* n)
{
	BoardState* currentBoard = n->getData();
	int xSum = currentBoard -> getXSum();
	int oSum = currentBoard -> getOSum();
	int boardSum = xSum + oSum;
	int rSum = MAX_SUM - boardSum;
	int turn = currentBoard ->getTurn();
	

	while(rSum != 0)
	{
		int lgResult = floor(log2(rSum));
		int powerResult = pow(2, lgResult);
		rSum = rSum - powerResult;
		BoardState* boardClone = currentBoard -> clone();
		
		int tempSum;
		if(turn == 0)
		{
			tempSum = oSum + powerResult;
			boardClone -> setOSum(tempSum);
			boardClone -> addOCount();
		}
		else if(turn == 1)
		{
			tempSum = xSum + powerResult;
			boardClone -> setXSum(tempSum);
			boardClone -> addXCount();
		}


	TreeNode* nextNode = new TreeNode(boardClone);
	insert(n, nextNode);
	
	
	if(boardClone->getOutcome() == GAME_IN_PROGRESS)
	{
		buildTree(nextNode);
		
	}	
	
	}
	
	return;
}

void TreeMaker::preOrder(TreeNode* n)
{
	BoardState* currentBoard = n->getData();
	currentBoard -> print();
	std::vector<TreeNode*> children = n->getChildren();
	int childrenSize = children.size() -1;
	for(int i=childrenSize; i>=0; i--)
	{
		preOrder(children.at(i));
	}
}

void TreeMaker::postOrder(TreeNode* n)
{
	BoardState* currentBoard = n->getData();
	std::vector<TreeNode*> children = n->getChildren();
	int childrenSize = children.size()-1;
	for(int i=childrenSize; i>=0; i--)
	{
		postOrder(children.at(i));
	}
	currentBoard->print();
}

void TreeMaker::levelOrder(TreeNode* n)
{
	std::queue<TreeNode*> nodeQueue;
	if(root != NULL)
	{
		nodeQueue.push(root);
		while(!nodeQueue.empty())
		{
			TreeNode* pointer = nodeQueue.front();
			nodeQueue.pop();
			BoardState* currentBoard = pointer->getData();
			currentBoard->print();
			std::vector<TreeNode*> children = pointer ->getChildren();
			int childrenSize = children.size() -1;
			for(int i= childrenSize; i >=0 ; i--)
			{
				nodeQueue.push(children.at(i));
			}
		}
	}
}

void TreeMaker::terminalPath(TreeNode* n)
{
	std::vector<TreeNode*> path;
	terminalPathRecursion(n,path, 0);
}	

void TreeMaker::terminalPathRecursion(TreeNode* n, std::vector<TreeNode*> path, int pathLength)
{
	
	std::vector<TreeNode*> children = n->getChildren();
	path.push_back(n);
	pathLength++;
	if(!children.size())
	{
		for(int i=0; i <pathLength; i++)
		{
			BoardState* currentBoard = path.at(i)->getData();
			currentBoard -> print();
		}
	
	}else
	{
		for(int i=children.size()-1; i>=0; i--)
		{

			terminalPathRecursion(children.at(i), path, pathLength);
			if(n = root)
				break;
		}
	}
}

