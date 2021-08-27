#include <iostream>
#include <cmath>
#define MAXSIZE 100001

int min(int y, int x);
using namespace std;

int main() {

	int n;
	int dp[MAXSIZE] = { 0, };

	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i - (int)pow((int)sqrt(i), 2) == 0) dp[i] = 1;
		else {
			dp[i] = i;
			//cout << dp[i] << "\n";
			for (int j = 1; j <= (int)sqrt(i); j++) {
				dp[i] = min(dp[i], 1 + dp[i - (int)pow(j, 2)]);
			}
		}
		//cout << i << "번째 항의 값 : " << dp[i] << "\n";

	}

	cout << dp[n];
	return 0;

}

int min(int x, int y) {
	if (x <= y) return x;
	else return y;
}