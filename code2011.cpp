#include <iostream>
#include <math.h>
#define MAXSIZE 5001

using namespace std;

void solution() {
	string input;
	int arr[MAXSIZE] = { 0, };

	cin >> input;

	if (input.length() == 1 && input[0] == '0') {
		cout << 0;
		return;
	}
	for (int i = 1; i <= input.length(); i++) {
		arr[i] = input[i - 1] - '0';
		//cout << i << "번째 입력 확인 : " << arr[i] << "\n";
	}

	int dp[MAXSIZE] = { 1,0, };
	for (int i = 1; i <= input.length(); i++) {
			//cout << "값 확인 : " << arr[i - 1] * 10 + arr[i] << "\n";
			if (arr[i] <= 9 && arr[i] >= 1) { //한자리수 암호
				dp[i] =(dp[i]+ dp[i - 1])%1000000;
			}
			if (i >= 2) {
				if ((arr[i - 1] * 10 + arr[i]) <= 26 && (arr[i - 1] * 10 + arr[i]) >= 10) {
					//두자리수 암호가 가능함
					dp[i] =(dp[i]+ dp[i - 2])% 1000000;
				}
			}
		//cout << i << "번째 dp의 값" << dp[i] << "\n";
	}

	cout << dp[input.length()];
	return;
}

int main() {

	solution();

	return 0;
}