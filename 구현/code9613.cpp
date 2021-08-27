#include <iostream>
using namespace std;

int gcd(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}


int main() {
	int t, n;
	cin >> t;
	

	for (int i = 0; i < t; i++) {
		cin >> n;
		int arr[100];
		long long ret=0;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		for (int j = 0; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				ret += gcd(arr[j], arr[k]);
				//cout << j << "와 " << k << "사이의 gcd :: " << gcd(arr[j], arr[k])<<"\n";
			}
		}
		cout << ret<<"\n";
	}
}