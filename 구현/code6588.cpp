#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int max=1000001;
	bool *prime;
	prime = new bool[max + 1];
	fill_n(prime, max + 1, 1); //��� true�� ����
	prime[0] = false;
	prime[1] = false;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i <= sqrt(max); i++)
		if (prime[i] == true)
			for (int j = i * 2; j < max; j += i)
				prime[j] = false;

	prime[2] = false; //Ȧ�� �Ҽ��� ���̹Ƿ�, 2 ����

	while (1) {
		int x;
		cin >> x;
		bool check = false;
		if (x == 0) break;

		for (int j = 3; j < max; j++) {
			if (prime[j] == true) //�Ҽ��̸�
			{
				if (prime[x - j] == true) { //���������� �Ҽ��̸�
					cout << x << " = " << j << " + " << x - j << "\n";
					check = true;
					break;
				}
			}
		}
		if (check == false) cout << "Goldbach's conjecture is wrong.";
		check = false;
	}

	return 0;
}