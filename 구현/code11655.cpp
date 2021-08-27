#include <iostream>
#include <string>
using namespace std;
void solution() {
	string tem;
	getline(cin,tem);
	for (int i = 0; i < tem.length(); i++) {
		if (isalpha(tem[i])) {
			if (isupper(tem[i])) {
				if (tem[i] + 13 > 'Z') tem[i] = (char)tem[i] -13;
				else tem[i] += 13;
			}
			else {
				if (tem[i] + 13 > 'z') tem[i] = (char)tem[i] - 13;
				else tem[i] += 13;
			}
		}

	}
	for (int i = 0; i < tem.length(); i++) {
		cout << tem[i];
	}
}

int main() {
	solution();
	return 0;
}
