#include <iostream>
#include <stack>

using namespace std;

void solution() {
	stack<int> arr;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string tem;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tem;
		if (tem == "push") {
			int num;
			cin >> num;
			arr.push(num);
		}
		else if (tem == "pop") {
			if (!arr.empty()) {
				cout <<arr.top() << "\n";
				arr.pop();
			}
			else cout << -1<<"\n";
		}
		else if (tem == "size") {
			cout <<arr.size() << "\n";
		}
		else if (tem == "empty") {
			cout <<arr.empty() << "\n";
		}
		else if (tem == "top") {
			if (!arr.empty()) {
				cout <<arr.top() << "\n";
			}
			else cout << -1<<"\n";
		}
	}
}

int main() {
	solution();
	return 0;
}