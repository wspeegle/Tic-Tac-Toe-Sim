#include "TreeNode.h"
#include <stdio.h>
#include<vector>

TreeNode::TreeNode()
{	
}



TreeNode::TreeNode(TreeNode* p, std::vector<TreeNode*> c, BoardState* d)
{
	parent = p;
	children = c;
	data = d;
}

TreeNode::TreeNode(BoardState* d)
{
	data = d;
	parent = NULL;
}

void TreeNode::setParent(TreeNode * n)
{
  parent = n;
}

void TreeNode::setChildren(std::vector<TreeNode *> c)
{
	children = c;
}

void TreeNode::addChild(TreeNode *c)
{
  children.push_back(c);
}

void TreeNode::setData(BoardState *d)
{
  data = d;
}


TreeNode * TreeNode::getParent() const
{
  return parent;
}

std::vector<TreeNode *> TreeNode::getChildren()
{
  return children;
}

BoardState * TreeNode::getData()
{
  return data;
}

