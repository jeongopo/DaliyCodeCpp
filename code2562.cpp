#include <iostream>
int main() {
	//9개의 배열 값 중 최대값 구하기
	int array[10];
	int i = 0;
	for (i = 0; i < 9; i++) {
		std::cin >> array[i];
		if (array[i] > 100 || array[i] < 1) i--;
	}

	int max = array[0];
	int mindex=0;
	for (i = 1; i < 9; i++) {
		if (max < array[i]) {
			max = array[i];
			mindex = i;
		}
	}
	std::cout << max<<'\n';
	std::cout << (mindex+1);

	return 0;
}