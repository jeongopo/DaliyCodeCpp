#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;
	int b;

	cin >> n;
	cin >> b;

	long long tem=0;
	int r=1;
	for (int i = n.length()-1; i >= 0; i--) {
		//cout << n.length() - i << "번째 공비 : " << r << "\n";

		if (isdigit(n[i])) {
			tem += (long long)(r * (int)(n[i]-'0'));
			//cout << n.length()-i << "번째 숫자" << (n[i] - '0') << "\n";

		}
		else if (isalpha(n[i])) {
			tem +=(long long)(r * (int)(n[i] - 'A' + 10));
			//cout << n.length() - i << "번째 숫자" << (n[i] - 'A' + 10) << "\n";
		}
		r = r * b;
		//cout << "중간 결과 : " << tem<<"\n";
	}
	cout << tem << "\n";
}