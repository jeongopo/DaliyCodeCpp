#include <iostream>
#include <math.h>
#define MAXSIZE 1001

using namespace std;
int max(int x, int y);

void solution() {
	int n;
	int arr[MAXSIZE] = { 0, };
	int dp[MAXSIZE] = { 0, };

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = arr[i];
		for (int j = 0; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
			//cout << "i : " << i << " , j : " << j<<" 일 때 : " << dp[i - j] + dp[j] << "\n";
		}
		//cout << i << "번째 최대 금액 : " << dp[i] << "\n";
	}

	cout << dp[n];

}

int main() {

	solution();
	return 0;
}

int max(int x, int y) {
	if (x >= y) return x;
	else return y;
}