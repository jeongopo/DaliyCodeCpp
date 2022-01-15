#include <iostream>
using namespace std;

/*
	문제 풀이
	- 앞선 설탕배달 문제와는 다르게, 무조건 큰 수부터 나눠가면 된다.
	- 과정을 단순하게 하기 위해 배열에 값을 담아 진행했다.
*/
int coin[6] = { 500,100,50,10,5,1 };
int main() {
	int n;
	cin >> n;

	n = 1000 - n;
	int ret = 0;
	for (int i = 0; i < 6; i++) {
		ret += n / coin[i];
		//cout << coin[i] << "�� " << (n / coin[i]) << "�� ����\n";
		n -= (n / coin[i]) * coin[i];
		if (n == 0)	break;
	}
	cout << ret << "\n";

	return 0;
}