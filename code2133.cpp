#include <iostream>
#define MAXSIZE 31

using namespace std;

int main() {
	int n;
	int dp[MAXSIZE] = { 0,0,3,0,};

	cin >> n;

	for (int i = 4; i <= n; i = i + 2) {
		dp[i] = dp[i-2] * 3;
		for (int j = 4; j <= i; j=j+2) {
			if (i == j) dp[i]=dp[i]+2; //전체 크기와 같을 경우 2가지만 나온다
			else {
				dp[i] = dp[i] + dp[i - j] * 2; //j크기는 무조건 2가지이므로 i-j의 경우수와 곱해준다
			}
			//cout << i << "번째 항의 값 : " << dp[i] << "\n";
	}

	cout << dp[n];
}