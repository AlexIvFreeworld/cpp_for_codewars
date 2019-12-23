/* Given two different positions on a chess board, find the least number of moves it would take
a knight to get from one to the other. 
The positions will be passed as two arguments in algebraic notation. For example, 
knight("a3", "b5") should return 1.

The knight is not allowed to move off the board. The board is 8x8.

For information on knight moves, see https://en.wikipedia.org/wiki/Knight_%28chess%29

For information on algebraic notation, see 
https://en.wikipedia.org/wiki/Algebraic_notation_%28chess%29

(Warning: many of the tests were generated randomly. 
If any do not work, the test cases will return the input, output, and expected output; 
please post them.) 


Assert::That(knight("a1", "c1"), Equals(2));
Assert::That(knight("a1", "f1"), Equals(3));
Assert::That(knight("a1", "f3"), Equals(3));
Assert::That(knight("a1", "f4"), Equals(4));
Assert::That(knight("a1", "f7"), Equals(5));

*/

#include <string>

int knight(std::string start, std::string finish) {
  return 0;
}

