#include <iostream>
using namespace std;

int main() {
	int dp[1001][10] = { 0, };
	int n;

	cin >> n;

	for (int i = 0; i < 10; i++) {
		dp[0][i] = 0;
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) { //n번째 자리수까지
		for (int j = 0; j <10; j++) { //마지막 수가 0~9인 케이스
			for (int k = 0; k <=j; k++) {
				//cout << i << "자리수의 마지막 수가 " << j << "인 숫자의 " <<k<<"케이스"<< dp[i - 1][k] << "\n";
				dp[i][j] = (dp[i][j]+ dp[i - 1][k])%10007;
			}
			//cout << "★"<<i << "자리수의 마지막 수가 " << j << "인 숫자 : " << dp[i][j] << "\n";
		}
	}

	int sum=0;
	for (int i = 0; i < 10; i++) {
		sum =(sum+ dp[n][i])%10007;
	}
	cout << sum<<"\n";
}