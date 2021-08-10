#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;
int main() {
	unsigned long k, n;
	cin >> k >> n;
	unsigned long maxval = 0;

	vector<unsigned long> arr;
	for (int i = 0; i < k; i++) {
		unsigned long tem = 0;
		cin >>tem;
		arr.push_back(tem);
		maxval = max(maxval, tem);
	}

	unsigned long start=1, end=maxval, mid;
	unsigned long ret = 0;

	while (start <= end) {
		mid = (start + end) / 2;
		//cout << "\n\n\n±æÀÌ : " << mid << "===========\n";

		unsigned long tem=0;
		for (int i = 0; i < k; i++) {
			if (arr[i]>=mid)	tem += arr[i] - mid;
		}

		if (tem >= n) {
			start = mid + 1;
			if (ret != 0) ret = max(ret, mid);
			else ret = mid;
		}
		else end = mid - 1;
	}
	cout << ret<<"\n";
	return 0;
}