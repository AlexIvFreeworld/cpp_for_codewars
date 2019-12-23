#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool f_comp(char ch)
{
	return true;
}
int main()
{
	string str = "asdhdsa";
	int len_pol;
	int str_size = str.length();
	int str_middle = str_size / 2;
	cout << str << "  " << str_size << endl;
	cout << str_middle << endl;
	string::iterator pTh = str.begin();
	string::iterator pTe = str.end() - 1;
	cout << str[0] << endl;
	cout << *pTh << endl;
	cout << *pTe << endl;
	cout << count_if(pTh, pTe, f_comp) << endl;
	if (*pTh == *pTe)
	{
		int len = count_if(pTh, pTe, f_comp) - 1;
		if (len == 0)
		{
			len_pol = 2;
			return len_pol;
		}
		else
		{
			int count_not_equal;
			for (int i = 0; i < len / 2; i++)
			{
				if (*(pTh + 1+i) != *(pTe - 1-i)) {
					count_not_equal++;
					break;
				}
			}
			if (count_not_equal == 0) {
				len_pol = len + 2;
				return len_pol;
			}
			else {
				//должны начать с начала сдвинув первый итератор на +1
			}
		}
	}
	else
	{
	}
	for (int i = 0; i < str_middle; i++)
	{
	}
	return len_pol;
}