// Count the smiley faces!
// Description:
// Given an array (arr) as an argument complete the function countSmileys that should return the total number of smiling faces.
// Rules for a smiling face:
// -Each smiley face must contain a valid pair of eyes. Eyes can be marked as : or ;
// -A smiley face can have a nose but it does not have to. Valid characters for a nose are - or ~
// -Every smiling face must have a smiling mouth that should be marked with either ) or D.
// No additional characters are allowed except for those mentioned.
// Valid smiley face examples:
// :) :D ;-D :~)
// Invalid smiley faces:
// ;( :> :} :] 

// Example cases:
// countSmileys([':)', ';(', ';}', ':-D']);       // should return 2;
// countSmileys([';D', ':-(', ':-)', ';~)']);     // should return 3;
// countSmileys([';]', ':[', ';*', ':$', ';-D']); // should return 1;

// Note: In case of an empty array return 0. You will not be tested with invalid input (input will always be an array). Order of the face (eyes, nose, mouth) elements will always be the same 
// Happy coding!
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <regex>
using namespace std;
int countSmileys(std::vector<std::string> arr)
{
	//vector<string> s = arr;
	int sum = 0;
	for(string i : arr){
		int j = 0;
	    int eyes = 0;
		int mouths = 0;
		int noses = 0;
		while(i[j] != '\0'){
			if(i[j] == ':' || i[j] == ';') eyes++;
			if(i[j] == ')' || i[j] == 'D') mouths++;
			if(i[j] == '-' || i[j] == '~') noses++;
			j++;
		}
		if(eyes > 0 && mouths > 0 && j == 2) sum++;
		if(eyes > 0 && mouths > 0 && noses > 0 && j == 3) sum++;
	}
  return sum;
}
int countSmileys_best(std::vector<std::string> arr)
{
	int count = 0;
	std::regex smiles_regex("[:|;](-|~)?[)|D]");

	for (auto& smile : arr) {
		if (std::regex_match(smile, smiles_regex))
			count++;
	}

	return count;
}
int main(){
	vector<string> sm, sm2, sm3, sm4;
    sm = {":)", ";(", ";}", ":-D"};
	sm2 = { ":>", ":~)", ":~)", ":~)", ";D", ";~>", ";~>" };
	sm3 = { ":>", ";>", ":)", ":~(", ":(", ":)", ":oD" };//Expected: equal to 2 Actual: 3
	sm4 = { ";->", ":->", ";>", ";)", ";~D", ":>", ";o)" };//Expected: equal to 2 Actual: 3
	cout << countSmileys(sm) << " - " << countSmileys_best (sm) << endl;
	cout << countSmileys(sm2) << " - " << countSmileys_best(sm2) << endl;
	cout << countSmileys(sm3) << " - " << countSmileys_best(sm3) << endl;
	cout << countSmileys(sm4) << " - " << countSmileys_best(sm4) << endl;
	cin.get();
	return 0;
}