#include <iostream>
#include <stack>

using namespace std;

void solution() {
	int t,j;
	cin >> t;

	for (int i = 0; i < t; i++) {
		stack<char> arr1, arr2;
		string tem;
		cin >> tem;
		
		for (j = 0; j < tem.length(); j++) {
			arr1.push(tem[j]);
		}
		for (j = 0; j <=tem.length(); j++) {
			if (j == tem.length()) { 
				if (!arr2.empty()) cout << "NO\n"; 
				else cout << "YES\n"; 
			}else {
				if (arr1.top() == ')') arr2.push(')');
				else if (arr1.top() == '(') {
					if (arr2.empty()) {
						cout << "NO\n";
						break;
					}
					else {
						arr2.pop();
					}
				}
				arr1.pop();
			}
		}
		
		 

	}
}

int main() {
	solution();
	return 0;
}
