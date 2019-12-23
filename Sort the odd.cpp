//You have an array of numbers.
//Your task is to sort ascending odd numbers but even numbers must be on their places.
//Zero isn't an odd number and you don't need to move it.If you have an empty array, you need to return it.
#include <iostream>
#include <vector>
using namespace std;
class Kata
{
public:
	std::vector<int> sortArray(std::vector<int> array)
	{
		if (array.size() < 2) {
			return array;
		}
		else {
			int p, temp;
			for (int i = 0; i < array.size() - 1; i++) {
				for (int j = 0; j < array.size() - 1 - i; j++) {
					p = j + 1;
					if (array[j] % 2 != 0 && array[p] % 2 != 0) {
						if (array[j] > array[p]) {
							temp = array[p];
							array[p] = array[j];
							array[j] = temp;
						}
					}
					else if (array[j] % 2 == 0) {
						continue;
					}
					else if (array[j] % 2 != 0 && array[p] % 2 == 0) {
						while (array[p] % 2 == 0 && p < array.size() - 1 - i) {
							p++;
						}
						if (array[p] % 2 == 0) {
							continue;
						}
						else {
							if (array[j] > array[p]) {
								temp = array[p];
								array[p] = array[j];
								array[j] = temp;
							}
						}
					}
				}
			}
			return array;
		}
	}
};
void sort_arr(int *arr, int size);
void show_arr(int *arr, int size);
int main() {
	int arr_orig[] = { 5, 3, 2, 8, 1, 4 };
	int size = sizeof(arr_orig) / sizeof(int);
	cout << "sizeof(arr) = " << sizeof(arr_orig) << "sizeof(int) = " << sizeof(int) << "size = " << size << endl;
	show_arr(arr_orig,size);
	cout << "------------------------------------------------------" << endl;
	sort_arr(arr_orig, size);
	cout << "0 - " << arr_orig[0] << endl;
	show_arr(arr_orig, size);
	cout << "------------------------------------------------------" << endl;
	//sort_arr(arr_orig, size);
	//show_arr(arr_orig, size);

	cin.get();
	return 0;
}
void sort_arr(int *arr, int size) {
	int p, temp;
	for (int i = 0; i < size-1; i++) {
		for (int j = 0; j < size-1-i; j++) {
			p = j + 1;
			if (arr[j] % 2 != 0 && arr[p] % 2 != 0) {
				if (arr[j] > arr[p]) {
					temp = arr[p];
					arr[p] = arr[j];
					arr[j] = temp;
				}
			}
			else if (arr[j] % 2 == 0) {
				continue;
			}
			else if (arr[j] % 2 != 0 && arr[p] % 2 == 0) {
				while (arr[p] % 2 == 0 && p < size-1-i) {
					p++;
				}
				if (arr[p] % 2 == 0) {
					continue;
				}
				else {
					if (arr[j] > arr[p]) {
						temp = arr[p];
						arr[p] = arr[j];
						arr[j] = temp;
					}
				}
			}
		}
	}
}
void show_arr(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		(i == size-1)? cout << arr[i] : cout << arr[i] << " , ";
	}
	cout << endl;
}
