#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n;
	cin >> n;

	int b;
	cin >> b;
	vector<int> arr;

	while (n>=1) {
		arr.push_back(n % b);
		n = n / b;
	}
	for (int i = arr.size()-1; i >=0 ; i--) {
		if (arr[i] < 10) cout << arr[i];
		else {
			cout << (char)('A' + arr[i]-10);
		}
	}
	cout <<"\n";
}