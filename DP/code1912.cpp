#include <iostream>
using namespace std;
#define MAXSIZE 100001

int max(int x, int y);

int main() {
	int n;
	int arr[MAXSIZE] = { 0, };
	int dp[MAXSIZE] = {0,};

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}


	dp[1] = arr[1];
	int maxret = arr[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		//cout << "비교 " << arr[i] << " : " << dp[i - 1] + arr[i] << "\n";
		maxret = max(maxret, dp[i]);
	}

	cout << maxret;
	return 0;
}

int max(int x, int y) {
	if (x >= y) return x;
	else return y;
}