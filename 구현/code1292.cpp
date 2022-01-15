#include <iostream>
using namespace std;

int arr[1001];

int main() {
	int a, b;
	cin >> a >> b;
	
	int index = 1;
	for (int i = 1; i < 50; i++) {
		for (int j = index; j < index + i; j++) {
			if (j > 1000) break;
			arr[j] = i;
		}
		index += i;
	}
	
	int sum = 0;
	for (int i = a; i <= b; i++) {
		sum += arr[i];
	}
	cout << sum << "\n";
	
}