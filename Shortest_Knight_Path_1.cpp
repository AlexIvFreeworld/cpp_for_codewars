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
	int Sx;
	int Sy;
	string D;
	int steps;
public:
	F(string str) {
		//map<char, int> chint;
		//chint.insert(make_pair('a', 1));
		//chint.insert(make_pair('b', 2));
		//chint.insert(make_pair('c', 3));
		//chint.insert(make_pair('d', 4));
		//chint.insert(make_pair('e', 5));
		//chint.insert(make_pair('f', 6));
		//chint.insert(make_pair('g', 7));
		//chint.insert(make_pair('h', 8));
		char arrX[8] = { 'a', 'b','c','d','e','f','g','h' };
		char arrY[8] = { '1', '2','3','4','5','6','7','8' };
		char chX = (str[0]);
		char chY = (str[1]);
		for (int i = 0; i < 8; i++) {
			if (arrX[i] == chX) {
				x = i + 1;
				break;
			}
		}
		for (int i = 0; i < 8; i++) {
			if (arrY[i] == chY) {
				y = i + 1;
				break;
			}
		}
		steps = 0;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void calcDirAndDistance(P objP) {
		Sx = objP.getX() - x;
		Sy = objP.getY() - y;
		if (Sx > 0 && Sy == 0) D = "E";
		else if (Sx > 0 && Sy < 0) D = "SE";
		else if (Sx > 0 && Sy > 0) D = "NE";
		else if (Sx == 0 && Sy > 0) D = "N";
		// here

	}
};
class Cell {
	int x;
	int y;
public:
	Cell(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};
class P {
	int x;
	int y;
public:
	vector<Cell> Z;
	P(string str) {
		char arrX[8] = { 'a', 'b','c','d','e','f','g','h' };
		char arrY[8] = { '1', '2','3','4','5','6','7','8' };
		char chX = (str[0]);
		char chY = (str[1]);
		for (int i = 0; i < 8; i++) {
			if (arrX[i] == chX) {
				x = i + 1;
				break;
			}
		}
		for (int i = 0; i < 8; i++) {
			if (arrY[i] == chY) {
				y = i + 1;
				break;
			}
		}
		// zone around P
		Cell objC0(x - 1, y + 1);
		Z.push_back(objC0);
		Cell objC1(x, y + 1);
		Z.push_back(objC1);
		Cell objC2(x + 1, y + 1);
		Z.push_back(objC2);
		Cell objC3(x - 1, y);
		Z.push_back(objC3);
		Cell objC4(x + 1, y);
		Z.push_back(objC4);
		Cell objC5(x - 1, y - 1);
		Z.push_back(objC5);
		Cell objC6(x, y - 1);
		Z.push_back(objC6);
		Cell objC7(x + 1, y - 1);
		Z.push_back(objC7);

	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void createZ() {

	}
};
int knight(std::string start, std::string finish);

int main() {
	string start = "a1";
	string finish = "f1";
	knight(start, finish);
	return 0;
}

int knight(std::string start, std::string finish) {
	F objF(start);
	//testing class methods
	cout << "Place F x = " << objF.getX() << " y = " << objF.getY() << endl;
	Cell objC(5, 5);
	cout << "objC x = " << objC.getX() << " y = " << objC.getY() << endl;
	objC.setX(8);
	objC.setY(8);
	cout << "objC x = " << objC.getX() << " y = " << objC.getY() << endl;
	P objP(finish);
	cout << "objP x = " << objP.getX() << " y = " << objP.getY() << endl;
	cout << "objP.Z[0].getX() = " << objP.Z[0].getX() << endl;
	for (Cell objC : objP.Z) {
		cout << objC.getX() << " " << objC.getY() << endl;
	}

	return 0;
}

