#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int tem;

	for (int i = 0; i < n; i++) {
		cin >> tem;
		arr.push_back(tem);
	}

	sort(arr.begin(), arr.end());
	
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret += (n - i) * arr[i];
	}

	cout << ret << "\n";
	return 0;
}