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
#include <string>
#include <algorithm>
using namespace std;
bool All_count(char ch);
int longest_palindrome(const std::string& s)
{
	int len_max_polindrom = 1;
	//считаем длинну строки
	int len_outside = s.length();
	if (len_outside == 0)
	{
		//если строка пустая завершаем программу с длинной 0
		len_max_polindrom = 0;
	}
	else if (len_outside == 1)
	{
		//если значение 1 завершаем программу с длинной 1
		len_max_polindrom = 1;
	}
	else if (len_outside > 1)
	{
		// внешний цикл, поиск совпадения начала и конца
		//устанавливаем итераторы на начало и конец
		string str = s;
		string::iterator it_s = str.begin();
		string::iterator it_end = str.end() - 1;
		//cout << "str : " << str << endl;
		for (int n = 0; n < len_outside - 1; n++)
		{
			// проходим все элементы от начала до конца
			it_s = str.begin() + n;
			it_end = str.end() - 1;
			for (int i = 0; i < len_outside - 1; i++)
			{
				//задаем переменные, с каждым циклом сдвигаем end на единицу к началу
				it_s = str.begin() + n;
				it_end = str.end() - 1 - i;
			//	cout << "start = " << *it_s << " n = " << n;
			//	cout << " end = " << *it_end << " i = " << i << endl;
				// проверяем совпадение пары начало- конец
				bool is_palindrome = false;
				if (*it_s == *it_end)
				{
					//cout << "possibly found palindrome" << endl;
					// внутренний цикл, при найденном совпадении перебор найденного полиндрома
					//находим длинну строки
					int len_inside;
					is_palindrome = true;
					len_inside = count_if(it_s, it_end + 1, All_count);
					//cout << "len_inside : " << len_inside << endl;
					for (int j = 1; j < len_inside / 2; j++)
					{
						//смещаем итераторы на шаг друг к другу
						it_s++;
						it_end--;
						if (*it_s != *it_end)
						{
							//если какой то символ не совпал выход из внутреннего цикла
							// с флагом нет
							is_palindrome = false;
							//	break;
							//cout << "is_palindrome = false; for pair" << endl;
							break;
						}
						//cout << "cycle three- " << j << endl;
					}
					if (is_palindrome)
					{
						//если флаг да, выход из цикла
						//длиной полиндрома
						if (len_inside > len_max_polindrom) {
							len_max_polindrom = len_inside;
						//	cout << "res = " << len_max_polindrom << endl;
						}
					}
				}
				else
				{
					// выход из вн цикла, сдвигаем начальный итератор вперед
				//	break;
				}
				//cout << "second loop-- " << i << endl;
				// если найден палиндром нужно выходить из второго цикла
				if (is_palindrome == true) {
					break;
				}
			}
			//cout << "First loop " << n << endl;
		}
	}
	return len_max_polindrom;
}
int longest_palindrome_1(const std::string& s)
{
	int maxlen = 0;
	for (int i = 0; i < s.size(); ++i)
		for (int j = 0; j < s.size(); ++j)
		{
			std::string sub = s.substr(i, s.size() - j);
			std::string rev = sub;
			std::reverse(rev.begin(), rev.end());

			if (sub == rev)
				maxlen = sub.size() > maxlen ? sub.size() : maxlen;
		}


	return maxlen;
}
int longest_palindrome_2(const std::string& s) {
	if (s.size() < 2) return s.size();

	auto isEqual = [&](auto x, auto y) {
		for (; x < y; x++, y--) if (s[x] != s[y]) return false;
		return true;
	};

	for (auto lenght = s.size(); lenght > 1; lenght--)
		for (auto i = 0; i + lenght - 1 < s.size(); i++)
			if (isEqual(i, i + lenght - 1)) return lenght;

	return 1;
}
bool Is_palindrom(string& str, string::iterator it_start, string::iterator it_end)
{
	bool result = true;
	cout << "str : " << str << endl;
	cout << "*it_start : " << *it_start << endl;
	cout << "*it_end : " << *it_end << endl;
	cout << "str.length() / 2 :" << str.length() / 2 << endl;
	if (str.length() >= 0 && str.length() <= 1)
		result = false;
	else
	{
		for (size_t i = 0; i < str.length() / 2; i++)
		{
			cout << "cycle : " << i << endl;
			if (*it_start != *it_end)
			{
				result = false;
				break;
			}
			else
			{
				it_start++;
				it_end--;
			}
		}
	}
	return result;
}
int main()
{
	//string s = "baablkj12345432133d";
	string a = "1 i1o1e.4. 4z7u8gldb ?pri5j5 gdg 5j5irp? bdlg8u7z4 .4.e1o1i 7yxi7bxcd  q";
	string s = "FourscoreandsevenyearsagoourfaathersbroughtforthonthiscontainentanewnationconceivedinzLibertyanddedicatedtothepropositionthatallmenarecreatedequalNowweareengagedinagreahtcivilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
	string a_res = " i1o1e.4. 4z7u8gldb ?pri5j5 gdg 5j5irp? bdlg8u7z4 .4.e1o1i ";
	string::iterator it_s = s.begin();
	string::iterator it_end = s.end() - 1;

 //   cout << "longest_palindrome(s) : " << longest_palindrome(s) << "  length s = " << s.length() << endl;
//	cout << "longest_palindrome(a) : " << longest_palindrome(a) << "  length a = " << a.length() << endl;
//	cout << "longest_palindrome(a_res) : " << longest_palindrome(a_res) << "  length a_res = " << a_res.length() << endl;
	cout << "longest_palindrome_1(a) : " << longest_palindrome_1(a) << "  length a = " << a.length() << endl;

	//cout << "Result : " <<  Is_palindrom(s, it_s, it_end) << endl;
	cin.get();
	return 0;
}
bool All_count(char ch)
{
	return true;
}
