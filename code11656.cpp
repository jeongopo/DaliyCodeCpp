#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void solution() {
	vector<string> arr;

	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		string tem;
		tem.append(str, i, str.length()-i);
		//cout << tem << "\n";
		arr.push_back(tem);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << "\n";
	}
}

int main() {
	solution();
	return 0;
}