#include <iostream>
using namespace std;


int stair(int num, int k);
int main() {
	int n;
	int DP[101][10] = {};
	cin >> n;
	for (int i = 0; i < 10; i++) {
		DP[1][i] = 1; //1자리수 전부 1로 세팅
	}
	for (int j = 2; j <=n; j++) {
		for (int i = 0; i <= 9; i++) {
			if (i == 0) { //자릿수가 0이면 증가만 할 수 있음
				DP[j][0]=DP[j-1][1];
			}
			else if (i == 9) { //자릿수가 9면 감소만 할 수 있음
				DP[j][9]=DP[j - 1][8];
			}else {//증가와 감소 값을 모두 더하기
				DP[j][i] = (DP[j - 1][i - 1] + DP[j - 1][i + 1]) % 1000000000;
			}
			}
	}

	int sum=0;
	for (int i = 1; i < 10; i++) {
		sum = (sum + DP[n][i]) % 1000000000;
	}
	cout << sum;
}

int stair(int num, int k) { //자리와 자릿수
	if (num == 1) { if (k == 0) return 0;
	else return 1; }
	if (num == 2) { //십의 자리에서 종료
		if (k == 1 || k==9 || k==0) return 1; //1,0은 증가만, 9는 감소만 가능
		else return 2;
	}
	else {
		if (k == 0) { //자릿수가 0이면 감소만 할 수 있음
			return stair(num - 1, k + 1);
		}
		else if (k == 9) { //자릿수가 9면 증가만 할 수 있음
			return stair(num - 1, k - 1);
		}
		else { //증가와 감소 값을 모두 더하기
			return stair(num - 1, k - 1) + stair(num - 1, k + 1);
		}
	}
}