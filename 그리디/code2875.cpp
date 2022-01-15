#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	if (n == 0 || m == 0) cout << 0 << "\n";

	int answer = 0;

	answer =min(n / 2,m);

	n = n - answer * 2;
	m = m - answer;
	
	if (n + m < k) {
		int lack = k - (n + m);

		if (lack % 3 == 0)	answer -= lack / 3;
		else answer -= (lack / 3)+1;
	}

	cout << answer << "\n";

	return 0;
}