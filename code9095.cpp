#include <iostream>

int main() {
	int DP[12] = { 0,1,2,4, };
	int ret[10];
	int i,j;
	int t = 0;
	int n = 0;

	for (i = 4; i <= 11; i++) {
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
	}

	std::cin >> t;

	for (j = 0; j < t; j++) { //t번의 테스트케이스 실행
		std::cin >> n;
		ret[j] = DP[n];
	}
	for (i = 0; i < t; i++) {
		std::cout << ret[i] << "\n";
	}
}