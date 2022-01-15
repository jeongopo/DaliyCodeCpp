#include <iostream>
#include <cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	bool btn[11];
	char channel[7];

	cin >> n >> m;

	int num = 0;
	memset(btn, true, 10);
	for (int i = 0; i < m; i++) {
		cin >> num;
		btn[num%10] = false;
	}

	int count = 0;
	int now = n;
	int ret = 0;
	bool IsBreak=false;

	if (n >= 100)	ret = n - 100;
	else ret =(n - 100) * (-1);

	for(int i=1;;i++){
		while (1) {
			if (btn[now % 10]) {
				now /= 10;
				count++;
				if (now == 0) {
					IsBreak = true;
					break;
				}
			}
			else break;
		}
		if (IsBreak) {
			ret = min(ret,count);
			break;
		}
		if (i > n)	break;
		now = n - i;
		count = i;
	}
	
	
	now = n;
	count = 0;
	IsBreak = false;
	for (int i = 1;; i++) {
		while (1) {
			if (btn[now % 10]) {
				now /= 10;
				count++;
				if (now == 0) {
					IsBreak = true;
					break;
				}
			}
			else break;
		}
		if (IsBreak) {
			ret = min(ret, count);
			break;
		}
		if (i > ret)	break;
		now = n +i;
		count = i;
	}

	cout << ret << "\n";

	return 0;
}