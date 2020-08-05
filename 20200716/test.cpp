#include <iostream>
using namespace std;

bool getNum(int numbers[], int length, int* Num) {
	if (numbers == nullptr || length <= 0)
		return false;
	for (int i = 0; i < length; ++i) {
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}
	for (int i = 0; i < length; ++i) {
		while (numbers[i] != i) {
			if (numbers[i] == numbers[numbers[i]]) {
				*Num = numbers[i];
				return true;
			}
			int tmp = numbers[i];
			numbers[i] = numbers[tmp];
			numbers[tmp] = tmp;
		}
	}
	return false;
}

int main() {
	int numbers[7] = { 2 ,3,1,0,2,5,3 };
	int length = sizeof(numbers) / sizeof(numbers[0]);
	cout << length << endl;
	int p;
	int ret = getNum(numbers, length, &p);
	cout << ret << endl;
	cout << p << endl;
	return 0;
}

