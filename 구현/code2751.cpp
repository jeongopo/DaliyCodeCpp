#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void solution() {
	int n;
	vector<int> arr;

	int tem = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tem;
		arr.push_back(tem);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++)
		cout << arr[i] << "\n";

}

int main() {
	solution();
	return 0;
}