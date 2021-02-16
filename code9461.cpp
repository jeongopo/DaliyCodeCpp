#include <iostream>
using namespace std;

long long solve(int n) {
	long long  p[101] = { 0,1,1,1,2, };
	for (int i = 5; i <= n; i++) {
		p[i] = p[i - 1] + p[i - 5];
		//cout << p[i]<<"\n";
	}

	return p[n];
}
int main() {
	int t;
	int n;
	long long ans[101];

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		ans[i] = solve(n);
	}
	for (int i = 0; i < t; i++) {
		cout << ans[i] << "\n";
	}
}