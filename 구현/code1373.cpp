#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int n;
	stack<int> arr;

	string tem;
	cin >> tem;
	if (tem.length() == 1 && tem[0] == '0') {
		cout << 0 << "\n";
		return 0;
	}

	for (int i = 0; i < tem.length(); i++) {
		arr.push(tem[i]-'0');
	}

	//cout << "stack 사이즈 : " << arr.size() << "\n";
	int r = 1;
	stack<int> ret;
	int temval=0;
	while (!arr.empty()) {
		temval += arr.top()*r;
		arr.pop();
		//cout << "값 확인 : " << temval << ", r: " << r << "\n";
		r = r * 2;
		if (r>=8) {
			r = 1;
			ret.push(temval);
			temval = 0;
		}
		if (arr.empty() && temval != 0) {
			ret.push(temval);
		}
	}
	
	while (!ret.empty()) {
		cout << ret.top();
		ret.pop();
	}
	cout << "\n";

	return 0;
}