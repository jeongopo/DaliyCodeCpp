#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main() {
	string tem;
	stack<int> arr;
	cin >> tem;
	if (tem.length()==1 && tem[0]=='0') {
		cout << 0 << "\n";
		return 0;
	}

	for (int i = tem.length()-1; i>=0;i--) {
		//cout << "N :: " << tem[i] << " 케이스 시작\n";
		int x = tem[i];
		int count =0;
		while (count<3) {
			arr.push(x%2);
			//cout << "PUSH :: " << x % 2 << "\n";
			x = x / 2;
			count++;
		}
	}
	bool Isstart = false;
	while (!arr.empty()) {
		if (!Isstart && arr.top() == 0);
		else {
			cout << arr.top();
			Isstart = true;
		}
		arr.pop();
	}
	return 0;
}