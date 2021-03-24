#include <iostream>
using namespace std;

long long gcd(long long x, long long y) {
	long long r=0;
	while (y != 0) {
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main() {
	long long a, b;
	
	cin >> a;
	cin >> b;

	//cout << gcd(a, b) << "\n";
	long long ret = gcd(a, b);
	for (int i = 0; i < ret; i++) {
		cout << 1;
	}
	cout << "\n";
	return 0;
}