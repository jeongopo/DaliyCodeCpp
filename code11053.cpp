#include <iostream>
using namespace std;

int main() {
	int n;
	int arr[1001];
	int dp[1001] = {0,1,};

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i]; //배열에 수 넣기
		dp[i] = 1; //1로 초기화
	}

	for (int i = 2; i <= n; i++) {
		//cout << i << "케이스 진행\n";
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[i - j]) {
				//cout << i << "번째 값으로부터 " << j << "의 거리를 두고 있을 때의 부분수열의 길이 : " << dp[i - j] + 1 << "\n";

				if (dp[i] < dp[i - j] + 1) {
					dp[i] = dp[i - j] + 1;
				}
			}
		}
	}

	int max = dp[1];
	for (int i = 2; i <= n; i++) {
		if (max <= dp[i]) max = dp[i];
	}
	cout << max;
}