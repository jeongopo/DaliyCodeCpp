#include <iostream>
#define MAX 500001
using namespace std;

int swap_count=0;
int arr[MAX];
int n;

void bubbleSort() {
	for (int i = n-1; i> 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				//cout << arr[j] << "<->" << arr[j + 1] << "\n";
				int tem = 0;
				tem = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tem;

				swap_count++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	bubbleSort();
	cout << swap_count <<"\n";
}