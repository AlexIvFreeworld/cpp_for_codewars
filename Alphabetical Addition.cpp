/* Instructions

Your task is to add up letters to one letter.
The function will be given a vector of letters, each one being a letter (of type char) to add.
Return type char too.
Notes:
Letters will always be lowercase.
Letters can overflow (see second to last example of the description)
No letters should return 'z'
Examples:
add_letters({'a', 'b', 'c'}) = 'f'
add_letters({'a', 'b'}) = 'c'
add_letters({'z'}) = 'z'
add_letters({'z', 'a'}) = 'a'
add_letters({'y', 'c', 'b'}) = 'd' # notice the letters overflowing
add_letters({}) = 'z' */

#include <vector>
#include <iostream>
using namespace std;

char add_letters(std::vector<char> letters) {
  // your code here
	int letter = 0;
	for (char ch : letters) letter += (int)ch;
	letter = letter - letters.size() * 96;
	while (letter > 26) letter -= 26;
	return (letter == 0) ? 'z' : (char)(letter+96);
}
int main (){
	vector<char> letters = {'a', 'b', 'c'};
	cout << add_letters(letters) << endl;
	cout << "----------------------------------" << endl;
	cout << 'a' + 'b' + 'c' << endl;
	char a = 'a';
	char b = 'b';
	char c = 'c';
	char f = 'f';
	char z = 'z';
	char y = 'y';

	cout << (int)a << endl;
	cout << (int)b << endl;
	cout << (int)c << endl;
	cout << (int)f << endl;
	cout << (int)z << endl;
	cout << (int)y << endl;

	cin.get();
	return 0;
}
