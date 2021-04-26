#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;

	int ret = 0;
	ret = n / 5 + n / 25 + n / 125;

	cout << ret << "\n";
	
	return 0;
}