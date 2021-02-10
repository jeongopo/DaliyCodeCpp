#include <iostream>
using namespace std;

int main() {
	int n;
	int arr[1001];
	int dp[1001] = {0, };

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin>>arr[i];
		dp[i] = arr[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + arr[i]) {
					dp[i] = dp[j] + arr[i];
				}
				//cout << i << ", " << j << "에서 최댓값 : "<< dp[i]<<"\n";
			}
		}
	}

	int max=dp[1];
	for (int i = 2; i <= n; i++) {
		if (max < dp[i]) max = dp[i];
	}
	cout << max;

}
