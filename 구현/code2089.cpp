#include <iostream>
#include <stack>
using namespace std;

int main() {
	long long n;
	stack<int> arr;

	cin >> n;

	if (n == 0) {
		cout << 0 << "\n";
		return 0;
	}
	while (n != 1) {
		if (n % (-2) ==-1) { //나머지가 음수
			n = (n / (-2)) + 1;
			//cout << "n :: " << n << "\n";
			arr.push(1);
		}
		else {
			arr.push(n%(-2));
			n = (n / (-2));
			//cout << "n :: " << n << "\n";
		}
	}
	arr.push(1);

	while (!arr.empty()) {
		cout << arr.top();
		arr.pop();
	}
	cout << "\n";
	
	return 0;
}