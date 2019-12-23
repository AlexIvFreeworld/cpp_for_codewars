/* Instructions

Given a number n, return the number of positive odd numbers below n, EASY!
oddCount(7) //=> 3, i.e [1, 3, 5]
oddCount(15) //=> 7, i.e [1, 3, 5, 7, 9, 11, 13]
Expect large Inputs! */
#include <iostream>
using namespace std;
int odd_count(int n){
  int sum_odd = 0;
  for(int first = 1; first < n; first+=2) sum_odd++;
  return sum_odd;
}
int odd_count_best(int n) {
	return (n%2 == 0)? n/2: (n-1)/2;
}
int odd_count_best_2(int n) {
	return n / 2;
}
int main(){
	cout << odd_count(7) << endl;
	cout << odd_count(15555555) << endl;
	cin.get();
	return 0;
}