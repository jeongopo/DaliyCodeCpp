#include <iostream>
#define MAXSIZE 1000

using namespace std;

int min(int x, int y) {
	if (x >= y) return y;
	else return x;
}

void solution() {
	int n;
	int arr[MAXSIZE];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int minindex=0;
	int tem=0;
	for (int i = 0; i < n; i++) { //정렬
		minindex = i;
		for (int j = i+1; j < n; j++) {
			if (arr[minindex] > arr[j]) minindex = j;
		}

		if (minindex != i) { //위치 교환
			tem = arr[minindex];
			arr[minindex] = arr[i];
			arr[i] = tem;
		}

	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
}

int main() {
	solution();
	return 0;
}