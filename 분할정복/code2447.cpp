#include <iostream>
#include <cstring>
#define MAX 2200
using namespace std;

int n;
bool star[MAX][MAX];

void divide(int x, int y, int size) {
	int blanksize = size / 3;
	for (int i = x+ blanksize; i < x+ blanksize *2; i++) {
		for (int j = y+ blanksize; j < y + blanksize *2; j++) {
			star[i][j] = false;
		}
	}
}

void check(int x, int y, int size) {
	if (star[x][y]) {
		divide(x, y, size);

		int newsize = size / 3;
		if (newsize == 1) return;
		for (int i = x; i <= x + newsize*2; i+=newsize) {
			for (int j = y; j <= y + newsize*2; j+=newsize) {
				check(i, j, newsize);
			}
		}
	}
}

void printStar() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (star[i][j]) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		memset(star[i], true, n);
	}
	

	check(0, 0, n);
	printStar();
	return 0;
}