#include <iostream>
using namespace std;

int main() {
	int train[11][2];
	for (int i = 0; i < 10; i++) {
		cin >> train[i][0] >> train[i][1];
	}

	int count = 0;
	int maxval=0;
	for (int i = 0; i < 10; i++) {
		count = count - train[i][0] + train[i][1];
		maxval = max(maxval, count);
	}
	cout << maxval << "\n";

	return 0;
}