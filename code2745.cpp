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
		//cout << n.length() - i << "��° ���� : " << r << "\n";

		if (isdigit(n[i])) {
			tem += (long long)(r * (int)(n[i]-'0'));
			//cout << n.length()-i << "��° ����" << (n[i] - '0') << "\n";

		}
		else if (isalpha(n[i])) {
			tem +=(long long)(r * (int)(n[i] - 'A' + 10));
			//cout << n.length() - i << "��° ����" << (n[i] - 'A' + 10) << "\n";
		}
		r = r * b;
		//cout << "�߰� ��� : " << tem<<"\n";
	}
	cout << tem << "\n";
}