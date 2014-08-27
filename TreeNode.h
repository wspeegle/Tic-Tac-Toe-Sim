#ifndef TREENODE_H
#define TREENODE_H
#include <vector>
#include "BoardState.h"
 
class TreeNode{
  	private:
		TreeNode * parent;
		std::vector<TreeNode *> children;
		BoardState * data;
   
	public:
		TreeNode();
		TreeNode(TreeNode*, std::vector<TreeNode*>, BoardState* d);
		TreeNode(BoardState*);
		void setParent(TreeNode *);
		void addChild(TreeNode *);
		void setData(BoardState *);
		void setChildren(std::vector<TreeNode*>);
		TreeNode * getParent() const;
		std::vector<TreeNode *> getChildren();
		BoardState * getData();
};
#endif
