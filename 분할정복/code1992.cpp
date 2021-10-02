#include <iostream>
using namespace std;

int map[70][70];
int n;

bool check(int x, int y, int size) {
	if (size == 1) return true;
	int start = map[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (start != map[i][j]) return false;
		}
	}
	return true;
}

void divide(int x, int y, int size) {
	if (check(x, y, size)) {
		cout << map[x][y];
	}
	else {
		int nextsize = size / 2;
		cout << "(";
		for (int i = x; i <= x+ nextsize; i+= nextsize) {
			for (int j = y; j <= y+ nextsize; j+= nextsize) {
				divide(i, j, nextsize);
			}
		}
		cout << ")";
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	char tem[70];

	for (int i = 0; i < n; i++) {
		cin >> tem;
		for (int j = n - 1; j >= 0; j--) {
			map[i][j] = tem[j]-'0';
		}
	}

	divide(0, 0, n);
	cout << "\n";

	return 0;
}