#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solution() {
	int n,k;
	vector<long long> arr;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> k;

	for (int i = 0; i < n; i++) {
		long long tem;
		cin >> tem;
		arr.push_back(tem);
	}

	sort(arr.begin(), arr.end());

	cout << arr[k - 1] << "\n";

	return;
}

int main() {
	solution();
	return 0;
}