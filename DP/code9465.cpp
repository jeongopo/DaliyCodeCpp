#include <iostream>
using namespace std;

int maxbetween(int x, int y);
int max(int x, int y, int z);

int main() {
	int sticker[100001][2];
	int dp[100001][3];
	int n = 0;
	int ret[100];
	int t = 0;

	cin >> t;
	for(int j=0;j<t;j++){
	cin >> n;
	for (int i = 1; i <= 2*n; i++) { //스티커 값 집어넣기
		if (i <=n) cin >> sticker[i][0];
		else cin >> sticker[i-n][1];
	}
	/*
	for (int i = 1; i <= 2 * n; i++) { //스티커 값 확인하기
		if (i <= n) cout << sticker[i][0]<<" ";
		else cout << sticker[i - n][1]<<" ";
		if (i == n) cout << "\n";
	}
	*/
	//1자리에서는 스티커의 값을 그대로 따름
	dp[1][0] = 0;
	dp[1][1] = sticker[1][0];
	dp[1][2] = sticker[1][1];

	for (int i = 2; i <=n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = maxbetween(dp[i - 1][0], dp[i - 1][2]) + sticker[i][0];
		dp[i][2] = maxbetween(dp[i - 1][0], dp[i - 1][1]) + sticker[i][1];
		//cout << i << "자리일 때의 값" << dp[i][0] << ", " << dp[i][1] << ", " << dp[i][2] << ", \n";
	}

	ret[j]=max(dp[n][0], dp[n][1], dp[n][2]);
	}

	for (int i = 0; i < t; i++) {
		cout << ret[i]<<"\n";
	}
	return 0;

}

int maxbetween(int x, int y) {
	if (x >= y) return x;
	else return y;
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
