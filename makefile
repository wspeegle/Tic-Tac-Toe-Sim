all:	BoardState.cpp BoardState.h TreeNode.cpp TreeNode.h t3solver.cpp TreeMaker.h TreeMaker.cpp
	g++ -std=c++11 -o t3solver t3solver.cpp BoardState.cpp TreeNode.cpp TreeMaker.cpp
	
BoardState:	BoardState.cpp
	g++ -std=c++11  BoardState.cpp
TreeNode:	TreeNode.cpp	
	g++ -std=c++11  TreeNode.cpp
TreeMaker:	TreeMaker.cpp BoardState.h BoardState.cpp TreeNode.h TreeNode.cpp
	g++ -std=c++11  TreeMaker.cpp BoardState.h BoardState.cpp TreeNode.h TreeNode.cpp
t3solver.cpp:
	g++ -std=c++11 -o t3solver.cpp
run:	
	./t3solver ${ARGS} >& output.log

clean:
	rm output.log t3solver