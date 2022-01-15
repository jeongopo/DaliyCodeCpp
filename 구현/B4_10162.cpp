#include <iostream>
using namespace std;

/*
	문제풀이
	- 앞선 거스름돈 문제와 동일한 방법으로 풀었다.
	- 대신, 1의 자리가 있는 수는 만들 수 없으므로, 입력을 받고 바로 return 하도록 했다.
*/

int buttons[3] = { 300,60,10 };
int ret[3] = { 0,0,0 };

int main() {
	int n;
	cin >> n;

	if (n % 10 != 0) {
		cout << -1 << "\n";
		return 0;
	}

	for (int i = 0; i < 3; i++) {
		ret[i] = n / buttons[i];
		n -= (n / buttons[i]) * buttons[i];
		if (n == 0)	break;
	}
	cout << ret[0] << " " << ret[1] << " " << ret[2] << "\n";

	return 0;
}
