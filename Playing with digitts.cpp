/* Instructions

Some numbers have funny properties. For example:
89 --> 8¹ + 9² = 89 * 1
695 --> 6² + 9³ + 5^4= 1390 = 695 * 2
46288 --> 4³ + 6^4+ 2^5 + 8^6 + 8^7 = 2360688 = 46288 * 51
Given a positive integer n written as abcd... (a, b, c, d... being digits) and a positive integer p 
we want to find a positive integer k, if it exists, such as the sum of the digits of n taken to the successive powers of p is equal to k * n. 
In other words:
Is there an integer k such as : (a ^ p + b ^ (p+1) + c ^(p+2) + d ^ (p+3) + ...) = n * k
If it is the case we will return k, if not return -1.
Note: n and p will always be given as strictly positive integers.
digPow(89, 1) should return 1 since 8¹ + 9² = 89 = 89 * 1
digPow(92, 1) should return -1 since there is no k such as 9¹ + 2² equals 92 * k
digPow(695, 2) should return 2 since 6² + 9³ + 5^4= 1390 = 695 * 2
digPow(46288, 3) should return 51 since 4³ + 6^4+ 2^5 + 8^6 + 8^7 = 2360688 = 46288 * 51 */
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class DigPow
{
public:
  static int digPow(int n, int p);
  static int digPow_best(int n, int p) {
	  long long sum = 0;
	  for (char digit : to_string(n)) {
		  sum += pow(digit - '0', p++);
	  }
	  return (sum / n) * n == sum ? sum / n : -1;
  }
};
int DigPow::digPow(int n, int p){
	string s = to_string(n);
	double sum = 0;
	char temp[2];
	int temp_i;
	for (char i : s) {
		temp[0] = i;
		temp_i = atoi(temp);
		sum += pow(temp_i,p++);
		//cout << i << " sum in for " << sum << endl;
	}
	return (floor(sum / n) == (sum / n) && (sum / n) != NULL ) ? (sum / n): -1;
}
int main(){
	string s;
	s = to_string(42);
	int n = 89;
	s = to_string(n);
	cout << s << "size = " << s.size() << endl;
	cout << DigPow::digPow(89,1) << endl;
	char ch = '8';
	int m = (int)ch-48;
	cout << "m= " << m << endl;
	cout << "--------------------------------" << endl;
	cout << DigPow::digPow_best(89, 1) << endl;
	cout << "--------------------------------" << endl;
	long long sum = 0;
	int p = 1;
	for (char digit : to_string(n)) {
		sum += pow(digit - '0', p++);
		cout << digit << " sum in for " << sum << endl;
	}
	cout << "--------------------------------" << endl;
	cout << pow(ch - '0', 2) << endl;
	cout << sqrt(ch) << endl;
	cin.get();
	return 0;
}

