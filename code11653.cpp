#include <iostream>
using namespace std;
int main() {
	long long n;
	cin>>n;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int q = 2;
	while (n >1) {
		if (n%q == 0) {
			cout << q << "\n";
			n = n / q;
		}
		else { //���������� ������ ���� ���ڷ�(���� ������ �ϹǷ� ��� �Ҽ�)
			q++;
		}
	}
	return 0;
}