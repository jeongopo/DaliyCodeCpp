#include <iostream>

int main() {
	int n = 0;
	std::cin >> n;
	
	int DP[1001] = { 0,1,2, };
	int i,j;

	for (i = 3; i <= n; i++) {
			DP[i] = (DP[i - 1] +DP[i-2])%10007;
	}

	std::cout << DP[n] << "\n";
}
