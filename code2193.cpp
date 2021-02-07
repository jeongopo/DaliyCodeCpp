#include <iostream>
using namespace std;

int main() {
	long long dp[91][2] = { 0, };
	int n;
	cin >> n;


	//배열 초기설정
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = 0; //이친수는 0으로 시작할 수 없다
	dp[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
		dp[i][1] = dp[i - 1][0]; //무조건 전 자리수가 0이어야만 한다
	}

	long long sum = 0;
	sum = dp[n][0] + dp[n][1];
	cout << sum<<"\n";
}