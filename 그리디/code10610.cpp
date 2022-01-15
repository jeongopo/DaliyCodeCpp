#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100001
using namespace std;

bool cmp(char x, char y) {
	return (x > y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char n[MAX];
	cin >> n;

	int IsContainsZero=false;
	int sum = 0;
	for (int i = 0; i < strlen(n); i++) {
		sum +=n[i]-'0';
		if (n[i] == '0')	IsContainsZero=true;
	}

	if (IsContainsZero && (sum % 3) == 0) {
		sort(n, n+strlen(n),cmp);
		cout << n << "\n";
	}
	else cout << "-1\n";

	return 0;
}