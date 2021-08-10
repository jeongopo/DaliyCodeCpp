#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

int main() {
	int k, n;
	unsigned int maxval = 0;
	unsigned int arr[MAX];
	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		maxval =max(arr[i], maxval);
	}

	unsigned int start=1, end= maxval, mid;
	unsigned int ret = 1;

	while (start <= end) {
		mid = (start + end) / 2;

		unsigned int tem = 0;
		for (int i = 0; i < k; i++) {
			tem += arr[i] / mid;
		}

		if (tem >= n) {
			start = mid + 1;
			ret = max(ret, mid);
		}
		else {
			end = mid - 1;
		}
	}

	cout << ret;
	return 0;
}