#ifndef TREEMAKER_H
#define TREEMAKER_H
#include "TreeNode.h"
#include "BoardState.h"

class TreeMaker{
	private:
		TreeNode * root;
		int size;
	
	public:
		TreeMaker();
		TreeMaker(TreeNode*);
		void setRoot(TreeNode *);
		void setSize(int);
		TreeNode* getRoot() const;
		int getSize() const;
		void insert(TreeNode *, TreeNode *);
		void buildTree(TreeNode* );
		void postOrder(TreeNode *);
		void preOrder(TreeNode *);
		void levelOrder(TreeNode *);
		void terminalPath(TreeNode*);
		void terminalPathRecursion(TreeNode*, std::vector<TreeNode*>, int);
};
#endif