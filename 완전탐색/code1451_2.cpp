#include <iostream>
using namespace std;

int arr[101][101] = { 0, };
long long MAX = 0;

long long sum(int sx, int sy, int ex, int ey) {
	long long ret = 0;
	for (int i = sy; i <= ey; i++) {
		for (int j = sx; j <= ex; j++) {
			ret += arr[i][j]; //�����ش�.
		}
	}
	return ret;
}

int main() {
	int N, M, s;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		char tem[51];
		cin >> tem;
		for (int j = 0; j < M; j++) {
			arr[i][j] = tem[j] - '0';
		}
	}
	//���簢���� ������ ����� �� 6�����̴�.
	//�� �������� �ε����� �˰� sum�� ����

	// 1�� case
	for (int i = 0; i < M - 2; i++) {
		for (int j = i + 1; j < M - 1; j++) {
			long long a = sum(0, 0, i, N - 1);
			long long b = sum(i + 1, 0, j, N - 1);
			long long c = sum(j + 1, 0, M - 1, N - 1);
			if (MAX < a * b * c)
				MAX = a * b * c;
		}
	}

	// 2�� case
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			long long a = sum(0, 0, M - 1, i);
			long long b = sum(0, i + 1, M - 1, j);
			long long c = sum(0, j + 1, M - 1, N - 1);
			if (MAX < a * b * c)
				MAX = a * b * c;
		}
	}

	// 3�� case
	for (int i = 0; i < M - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			long long a = sum(0, 0, i, N - 1);
			long long b = sum(i + 1, 0, M - 1, j);
			long long c = sum(i + 1, j + 1, M - 1, N - 1);
			if (MAX < a* b* c)
				MAX = a * b * c;
		}
	}

	// 4�� case
	for (int i = M - 1; i > 0; i--) {
		for (int j = 0; j < N - 1; j++) {
			long long a = sum(i, 0, M - 1, N - 1);
			long long b = sum(0, 0, i - 1, j);
			long long c = sum(0, j + 1, i - 1, N - 1);
			if (MAX < a * b * c)
				MAX = a * b * c;
		}
	}

	// 5�� case
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			long long a = sum(0, 0, M - 1, i);
			long long b = sum(0, i + 1, j, N - 1);
			long long c = sum(j + 1, i + 1, M - 1, N - 1);
			if (MAX < a* b* c)
				MAX = a * b * c;
		}
	}

	// 6�� case
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < M - 1; j++) {
			long long a = sum(0, i, M - 1, N - 1);
			long long b = sum(0, 0, j, i - 1);
			long long c = sum(j + 1, 0, M - 1, i - 1);
			if (MAX < a * b * c)
				MAX = a * b * c;
		}
	}

	//���� long long Ÿ���� ����ϰ����ϸ� lld�� ����Ѵ�.

	printf("%lld", MAX);
	//cout << MAX << endl;
	return 0;

}