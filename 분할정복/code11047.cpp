#include <iostream>
#define MAX 11
using namespace std;
int n, k;
int coin[MAX];
int mincoin=0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	for (int i = n - 1; i >=0; i--) {
		if (k == 0) break;
		if (k < coin[i]) continue;
		mincoin += k / coin[i];
		k = k % coin[i];
	}

	cout << mincoin << "\n";
	return 0;
}