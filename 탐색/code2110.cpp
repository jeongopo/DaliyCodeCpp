#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;

int main() {
	int n, c;
	cin >> n >> c;
	int house[MAX];

	for (int i = 0; i < n; i++) {
		cin >> house[i];
	}
	sort(house, house + n);

	int start=1, end=(house[n-1]-house[0]), mid;
	int ret = 0; //최소거리의 최댓값

	while (start <= end) {
		mid = (start + end) / 2;
			
		int prev = house[0];
		int tem = 1;
		for (int i = 1; i < n; i++) {
			if (house[i] - prev >= mid) {
				tem++;
				prev = house[i];
			}
		}

		if (tem >= c) {
			ret = max(ret, mid);
			start = mid + 1;
		}
		else end = mid - 1;
	}

	cout << ret << "\n";
	return 0;
}