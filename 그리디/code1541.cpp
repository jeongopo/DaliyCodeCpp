#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> num;
	vector<char> sign;

	string input;
	cin >> input;

	int tem = 0;
	for (int i = 0; i < input.length(); i++) {
		if (isdigit(input[i])) {
			tem = tem * 10 + (input[i] - '0');
		}
		else {
			num.push_back(tem);
			sign.push_back(input[i]);
			tem = 0;
		}
		if (i == input.length() - 1) {
			num.push_back(tem);
		}
	}

	bool IsChangeable = false;
	for (int i = 0; i < sign.size(); i++) {
		if (IsChangeable) {
			if (sign[i] == '+')	sign[i] = '-';
		}
		else if (sign[i] == '-') {
			IsChangeable = true;
		}
	}
	
	int ret = num[0];
	for (int i = 0; i < num.size()-1; i++) {
		if (sign[i] == '+') {
			ret += num[i+1];
		}
		else {
			ret -= num[i + 1];
		}
		//cout << "ÇöÀç ret : " << ret << "\n";
	}

	cout << ret << "\n";
	return 0;
}