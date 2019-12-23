/* Instructions

#Fold an array
In this kata you have to write a method that folds a given array of integers by the middle x-times.
An example says more than thousand words:
Fold 1-times:
[1,2,3,4,5] -> [6,6,3]

A little visualization (NOT for the algorithm but for the idea of folding):

 Step 1         Step 2        Step 3       Step 4       Step5
                     5/           5|         5\          
                    4/            4|          4\      
1 2 3 4 5      1 2 3/         1 2 3|       1 2 3\       6 6 3
----*----      ----*          ----*        ----*        ----*


Fold 2-times:
[1,2,3,4,5] -> [9,6]
As you see, if the count of numbers is odd, the middle number will stay. Otherwise the fold-point is between the middle-numbers, so all numbers would be added in a way.
The array will always contain numbers and will never be null. The parameter runs will always be a positive integer greater than 0 and says how many runs of folding your method has to do.
If an array with one element is folded, it stays as the same array.
The input array should not be modified!
Have fun coding it and please don't forget to vote and rank this kata! :-) 
I have created other katas. Have a look if you like coding and challenges. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Kata
{
public:
    std::vector<int> foldArray(std::vector<int> array, int runs)
    {
		vector<int> v, v_out;
		vector<int>::iterator it_start, it_end;
		for (int i = 0; i < runs; i++){
			(i == 0) ? v = array : v = v_out;
			v_out.clear();
			it_start = v.begin();
			it_end = v.end()-1;
			for(unsigned int j = 0; j < v.size()/2; j++){
				v_out.push_back((*it_start++)+(*it_end--));
				//cout << "j= " << j << "*it_start = " << *it_start << "*it_end = " << *it_end << endl;
				//it_start++;
				//it_end--;
			}
			if (v.size() % 2 != 0) v_out.push_back((v[v.size()/2]));
		}
        return v_out;
    }
	void Show(vector<int> arr){
		for(int i : arr){
			cout << i << ", ";
		}
		cout << endl;
	}
	std::vector<int> foldArray_best(std::vector<int> a, int runs)
	{
		for (; runs > 0; --runs)
		{
			const auto half = a.size() / 2;
			std::transform(std::cbegin(a), std::cbegin(a) + half, std::crbegin(a), std::begin(a), std::plus<int>());
			a.resize((a.size() + 1) / 2);
		}
		return a;
	}
};

int main(){
	vector<int> v = {1,2,3,4,5};
	vector<int> v3 = { -9, 9, -8, 8, 66, 23 };
	Kata K;
	vector<int> v2,v4;
	v2 = K.foldArray(v,2);
	K.Show(v2);
	v4 = K.foldArray(v3, 1);
	K.Show(v4);
	cin.get();
	return 0;
}















