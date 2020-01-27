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
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class F {
    int x;
    int y;
    int steps;
public:
    F(string str) {
        map<char, int> chint;
        chint.insert(make_pair('a', 1));
        chint.insert(make_pair('b', 2));
        chint.insert(make_pair('c', 3));
        chint.insert(make_pair('d', 4));
        chint.insert(make_pair('e', 5));
        chint.insert(make_pair('f', 6));
        chint.insert(make_pair('g', 7));
        chint.insert(make_pair('h', 8));
        char arrX[8] = {'a', 'b','c','d','e','f','g','h'};
        char arrY[8] = { '1', '2','3','4','5','6','7','8'};
        char chX = (str[0]);
        char chY = (str[1]);
        steps = 0;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
};

int knight(std::string start, std::string finish);

int main() {
    string start = "a1";
    string finish = "a6";
    knight(start, finish);
    return 0;
}

int knight(std::string start, std::string finish) {
    F objF(start);
    cout << "Place F x = " << objF.getX() << " y = " << objF.getY() << endl;
    return 0;
}

