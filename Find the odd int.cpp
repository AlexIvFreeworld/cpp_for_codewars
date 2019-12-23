/* Instructions

Given an array, find the int that appears an odd number of times.
There will always be only one integer that appears an odd number of times.

Fundamentals */

#include <vector>
#include <iostream>
#include <functional>
#include <numeric>
using namespace std;

int findOdd(const std::vector<int>& numbers){
  //your code here
  //int temp;
  int sum = 0;
for (const int i : numbers){
	//temp = i;
	for(const int j : numbers){
		if (j == i) sum++; 
	}
	if (sum%2 != 0) return i; 
}
return 0;
}
int findOdd_best_1(const std::vector<int>& numbers) {
  return std::accumulate(numbers.cbegin(), numbers.cend(), 0, std::bit_xor<>());
}
int findOdd_best_2(const std::vector<int>& numbers){
  for (auto elem: numbers){
    if (std::count(numbers.begin(), numbers.end(), elem) % 2 != 0) {
      return elem;
    }
  }
  return 0;
}
int main(){
	vector<int> arr = {20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5}; 
	cout << findOdd(arr) << endl;
	cin.get();
	return 0;
}