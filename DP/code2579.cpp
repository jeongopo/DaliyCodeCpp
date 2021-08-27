#include <iostream>
#define MAXSIZE 301

using namespace std;

int max(int x, int y);

int main() {
	int n;
	int arr[MAXSIZE] = { 0, };

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int dp[MAXSIZE][2];
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = arr[1];
	dp[1][1] =0;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + arr[i];
		dp[i][1] = dp[i - 1][0] + arr[i];
		//cout << i << "번째 자리 ( " << dp[i][0]<<","<<dp[i][1] << ")\n";

	}

	cout << max(dp[n][0], dp[n][1]);
}

int max(int x, int y) {
	if (x >= y) {
		return x;
	}else return y;
}
