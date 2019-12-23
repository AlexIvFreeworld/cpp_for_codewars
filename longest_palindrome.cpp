/* Instructions

Longest Palindrome
Find the length of the longest substring in the given string s that is the same in reverse. 
As an example, if the input was “I like racecars that go fast”, the substring (racecar) length would be 7. 
If the length of the input string is 0, the return value must be 0. 
Example:
"a" -> 1 
"aab" -> 2  
"abcde" -> 1
"zzbaabcd" -> 4
"" -> 0

Fundamentals */

#include <iostream>
#include <vector>
using namespace std;
int longest_palindrome(const std::string &s)
{
	vector<char> v,v1,v2;
	vector<char>::iterator it_s, it_end, it_temp;
	for (char ch : s) {
		v.push_back(ch);
	}
	it_s = v.begin();
	unsigned int sum_pal = 0;
	for (char ch : v) {
		//it_end = find(++it_s, v.end(), ch);
		it_end = v.end()-1;
		for (; it_end != it_s; it_end--) {
			if (ch == *it_end) break;
			//break;
		}
		if (it_end == it_s) cout << "elem is not found" << endl;
		else {
			it_temp = it_s;
			cout << *it_end << endl;
			for (; it_end != it_s; it_end--,it_temp++) {
				cout << *it_end << ", ";
				v2.push_back(*it_end);
				v1.push_back(*it_temp);
			}
			cout << *it_end << ", outside";
			v2.push_back(*it_end);
			v1.push_back(*it_temp);
			cout << endl;
			for (char ch : v1) cout << ch << ", ";
			cout << endl;
			if (v2.size() > sum_pal && v1 == v2) sum_pal = v2.size();
			cout << "sum_pal = " << sum_pal << endl;
			v1.clear();
			v2.clear();
		}
		it_s++;
	}
	if (v.size() == 0) return 0;
	else if (v.size() > 0 && sum_pal == 0) return 1;
    else return sum_pal; //your code here
}
int main (){
	string s = "baablkj12345432133d";
	cout << longest_palindrome(s) << endl;
	cin.get();
	return 0;
}
