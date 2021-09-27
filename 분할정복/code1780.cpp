#include <iostream>
#define MAX 2200
using namespace std;

int n;
int answer[3];
int paper[MAX][MAX];

bool check(int x,int y,int size) {
	int start = paper[x][y];
	for (int i = x; i < x+size; i++) {
		for (int j = y; j < y+size; j++) {
			if (start != paper[i][j]) return false;
		}
	}
	return true;
}

void divide(int x, int y, int size) {
	if (check(x, y, size)) {
		answer[paper[x][y] + 1]++;
	}
	else {
		int nextsize = size / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				divide(x + nextsize * i, y + nextsize * j, nextsize);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	divide(0, 0, n);
	cout << answer[0] << "\n";
	cout << answer[1] << "\n";
	cout << answer[2] << "\n";
}