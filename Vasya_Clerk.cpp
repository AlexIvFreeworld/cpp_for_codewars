/*The new "Avengers" movie has just been released!There are a lot of people at the cinema box office standing in a huge line.
Each of them has a single 100, 50 or 25 dollar bill.An "Avengers" ticket costs 25 dollars.

Vasya is currently working as a clerk.He wants to sell a ticket to every single person in this line.

Can Vasya sell a ticket to every person and give change if he initially has no moneyand sells the tickets strictly in the order people queue ?

Return YES, if Vasya can sell a ticket to every personand give change with the bills he has at hand at that moment.Otherwise return NO. */

/*
tickets({ 25, 25, 50 }) // => YES 
tickets({ 25, 100 }) // => NO. Vasya will not have enough money to give change to 100 dollars
tickets({ 25, 25, 50, 50, 100 }) // => NO. Vasya will not have the right bills to give 75 dollars of change (you can't make two bills of 25 from one of 50)
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

std::string tickets(const std::vector<int> peopleInLine) {
	// your code here
	vector<int> s_25, s_50;
	string answer;
	for (int cash : peopleInLine) {
		if (cash == 25) {
			s_25.push_back(cash);
		}
		else if (cash == 50) {
			if (s_25.empty) {
				answer = "NO";
				break;
			}
			else {
				s_50.push_back(cash);
				s_25.pop_back();
			}
		}
		else if (cash == 100) {
			if ((s_50.empty() && s_25.size() < 3) || (!s_50.empty() && s_25.empty()) ) {
				answer = "NO";
				break;
			}
			else if (!s_50.empty() && !s_25.empty()) {
				s_50.pop_back();
				s_25.pop_back();
			}
			else if (s_50.empty() && s_25.size() >= 3) {
				for (int i = 0; i < 3; i++) {
					s_25.pop_back();
				}
			}
			else {
				cout << "Other case" << endl;
			}
		}
	}
	return answer;
}