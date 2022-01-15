#include <iostream>
#include <cstring>
#define MAX 3080
using namespace std;

int n;
bool star[MAX][MAX*2];

void showStar() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2-1; j++) {
			if (star[i][j])	cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
}

void check(int x, int y, int size) { //꼭짓점이 (x,y)이고 높이가 size인 삼각형
	if (size >=3) {
		int halfSpace =size/2-1;
		for (int i = x+size/2; i < x+size; i++) {
			for (int j = y - halfSpace; j <= y + halfSpace; j++) {
				star[i][j] = false;
			}
			halfSpace--;
		}
		int newsize = size / 2;
		check(x, y, newsize);
		check(x +newsize, y -newsize, newsize);
		check(x + newsize, y+newsize, newsize);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = n-i-1; j <n+i; j++) {
			star[i][j] = true;
		}
	}

	check(0, n-1, n);

	showStar();

	return 0;
}