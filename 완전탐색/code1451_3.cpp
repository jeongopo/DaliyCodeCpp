#include <iostream>
#include <algorithm>
#define MAX 101 
using namespace std;

int arr[MAX][MAX];
int n, m;

long long max(long long x, long long y) {
	if (x > y)	return x;
	else return y;
}

long long maxResult(long long x, long long y, long long z, long long w) {
	if (x > y) {
		if (x > z) {
			if (x > w)	return x;
			else return w;
		}return z;
	}
	else {
		if (y > z) {
			if (y > w)	return y;
			else return w;
		}return z;
	}
}
long long col_divide() {
	if (m < 3)	return 0;
	long long maxval = 0;
	long long a = 0, b = 0, c = 0;
	for (int i = 0; i < m - 2; i++) {
		for (int j = 1; j < m - 1 - i; j++) {

			for (int row = 0; row < n; row++) {
				for (int col = 0; col < m; col++) {
					if (col <= i)	a += arr[row][col];
					else if (col <= i + j)	b += arr[row][col];
					else c += arr[row][col];
				}
			}

			maxval = max(maxval, a * b * c);
			a = 0;
			b = 0;
			c = 0;
		}
	}
	return maxval;
}

long long row_divide() {
	if (n < 3)	return 0;
	long long maxval = 0;
	long long a = 0, b = 0, c = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 1; j < n - 1 - i; j++) {

			for (int row = 0; row < n; row++) {
				for (int col = 0; col < m; col++) {
					if (row <= i)	a += arr[row][col];
					else if (row <= i + j)	b += arr[row][col];
					else c += arr[row][col];
				}
			}

			maxval = max(maxval, a * b * c);
			a = 0;
			b = 0;
			c = 0;
		}
	}
	return maxval;
}

long long bigcol_divide() {
	if (n < 2 || m < 2)	return 0;
	long long maxval = 0;
	long long a = 0, b = 0, c = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {

			for (int row = 0; row < n; row++) {
				for (int col = 0; col < m; col++) {
					if (row <= i) {
						if (col <= j)	a += arr[row][col];
						else b += arr[row][col];
					}
					else c += arr[row][col];
				}
			}

			maxval = max(maxval, a * b * c);
			a = 0;
			b = 0;
			c = 0;

			for (int row = 0; row < n; row++) {
				for (int col = 0; col < m; col++) {
					if (row > i) {
						if (col <= j)	a += arr[row][col];
						else b += arr[row][col];
					}
					else c += arr[row][col];
				}
			}

			maxval = max(maxval, a * b * c);

			a = 0;
			b = 0;
			c = 0;
		}
	}
	return maxval;
}

long long bigrow_divide() {
	if (n < 2 || m < 2)	return 0;
	long long maxval = 0;
	long long a = 0, b = 0, c = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {

			for (int row = 0; row < n; row++) {
				for (int col = 0; col < m; col++) {
					if (col <= j) {
						if (row <= i)	a += arr[row][col];
						else b += arr[row][col];
					}
					else c += arr[row][col];
				}
			}

			maxval = max(maxval, a * b * c);
			a = 0;
			b = 0;
			c = 0;

			for (int row = 0; row < n; row++) {
				for (int col = 0; col < m; col++) {
					if (col > j) {
						if (row <= i)	a += arr[row][col];
						else b += arr[row][col];
					}
					else c += arr[row][col];
				}
			}

			maxval = max(maxval, a * b * c);
			a = 0;
			b = 0;
			c = 0;
		}
	}
	return maxval;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//cout << "3¹ø\n";

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		char tem[51];
		cin >> tem;
		for (int j = 0; j < m; j++) {
			arr[i][j] = tem[j] - '0';
		}
	}

	cout << maxResult(col_divide(), row_divide(), bigcol_divide(), bigrow_divide()) << "\n";
	return 0;
}