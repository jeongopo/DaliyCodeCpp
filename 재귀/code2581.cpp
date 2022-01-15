#include <iostream>
using namespace std;

bool Isprime(int num){
	if (num == 1)	return false;
	for (int i = 2; i < num; i++) {
		if (num % i == 0)	return false;
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;

	int sum = 0;
	int min = -1;
	for (int i = n; i <=m; i++) {
		if (Isprime(i)) {
			if (min == -1)	min = i;
			sum += i;
		}
	}

	if (min == -1)	cout << min << "\n";
	else {
		cout << sum << "\n";
		cout << min << "\n";
	}


	return 0;
}