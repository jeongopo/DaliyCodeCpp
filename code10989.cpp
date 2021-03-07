#include <iostream>
using namespace std;


void solution() {
	int n;
	int arr[10001] = { 0, };

	int tem = 0;

	//cin,cout 속도 줄이기
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tem;
		arr[tem]++;
	}

	for (int i = 1; i <= 10000; i++) {
			for (int j = 0; j < arr[i]; j++) {
				cout << i << "\n";
		}
	}

}

int main() {
	solution();
	return 0;
}