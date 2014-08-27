Took a different approach rather than simply using nodes that hold arrays to the game board order to maximize time efficiency.

___|___|___
___|___|___
   |   | 
If we assume a typical 3x3 board, and X always goes first, we can easily represent the board using two integers - the xSum and oSum.

To do this, we use powers of 2 to represent each space on the board:

_0_|_1_|_2_										    _1_|_2_|_4_
_3_|_4_|_5_     -> 2^0, 2^1, etc. so each space on the board is a unique number: _8_|_16|_32
 6 | 7 | 8  										    _64|128|256

So for example, say we have the board      X | O | X
						 X | O | X
						 * | * | *	
This means the xSum = 1 + 4 + 8 + 32 = 45, and the oSum = 2 + 16 =18.

To go from a sum to the location on the board, we can take the floor of the lg of the number. i.e. for xSum = 45:
	lg(45)	= 5.49... floor of that is 5, so we have an X at position 5. To get the next location we subtract 2^5 from 45, so we get 13.
	Keep repeating the process and you will eventually get the location for all X and O values.

Finding a winning board was much more difficult. If there are only 3 X's, there are 8 sum values you have to check for. However, for the case
where you have 4 and 5 X's you have to check many more winning sums, which ruins the efficiency of this method. As a solution, we can use the
bitwise '&' operation to check the sums. i.e. since 7 = 00000111 we can run the & operation to check any sum against that value, and if the xSum
contains an X at 1,2, and 4 the result will be 00000111, or 7. 

45 = 000101101
7  = 000000111
   &___________
     000000101   = 5, which is not a winning sum



TO RUN: make ARGS="filename" run

This automatically sends output to output.log

Average run time for creating the tree for an empty board is 300ms. 


