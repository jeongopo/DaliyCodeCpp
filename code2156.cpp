#include <iostream>
using namespace std;

int max(int x, int y, int z);

int main() {
	int n;
	int wine[10001];
	int dp[10001][3];

	cin >> n;

	for (int i = 1; i <=n; i++) {
		cin >> wine[i];
	}

	dp[1][0] = 0;
	dp[1][1] = wine[1];
	dp[1][2] = 0;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = dp[i - 1][0] + wine[i];
		dp[i][2] = dp[i - 1][1] + wine[i];
	}

	cout << max(dp[n][0], dp[n][1], dp[n][2]);
}


int max(int x, int y, int z) {
	if (x >= y) {
		if (x >= z) return x;
		else return z;
	}
	else {
		if (y >= z) return y;
		else return z;
	}
}