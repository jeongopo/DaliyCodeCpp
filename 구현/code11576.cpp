#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int main() {
	int a, b;
	cin >> a;
	cin >> b;

	int m;
	cin >> m;

	long long tem=0;

	for (int i = m-1; i >=0; i--) {
		int x;
		cin >> x;
		tem += x * pow(a, i);
		//cout << "tem :: " << tem << "\n";
	}
	//cout << "변환 완료 : " << tem << "\n";
	if (tem == 0) {
		cout << 0 << "\n";
		return 0;
	}

	stack<int> arr;
	for (int i = 1;tem>=1; i++) {
		arr.push(tem%b);
		tem = tem / b;
	}

	while (!arr.empty()) {
		cout << arr.top()<<" ";
		arr.pop();
	}
	cout << "\n";
	return 0;
}