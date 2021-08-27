#include <iostream>
using namespace std;

int solve(int n,int k) {
	int dp[201][201] = { 0, };

	for (int i = 0; i <= n; i++) {
		dp[i][1] = 1;
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			for (int p = 1; p <= k; p++) {
				dp[i][p] = (dp[i][p]+dp[j][p - 1])% 1000000000;
			}
		}			
		//cout << "정수 " << i << "를 " << k << "개의 정수로 표현하는 경우의 수 : " << dp[i][k]<<"\n";

	}
	return dp[n][k];

}

int main() {
	int k;
	int n;
	
	cin >> n;
	cin >> k;

	cout<<solve(n, k)<<"\n";


}