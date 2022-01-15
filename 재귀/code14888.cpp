#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num[12];
int mid_operator[4];
int minval = 0;
int maxval = 0;
vector<int> order; 
int n;

int calculate() {
	int sum = num[0];
	for (int i = 0; i < n-1; i++) {
		switch (order[i])
		{
		case 0:
			sum += num[i + 1];
			break;
		case 1:
			sum -= num[i + 1];
			break;
		case 2:
			sum *= num[i + 1];
			break;
		case 3:
			if (sum < 0) {
				sum = ((sum) * (-1)) / num[i + 1];
				sum *= (-1);
			}
			else sum /= num[i + 1];
		default:
			break;
		}
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> mid_operator[i];
	}
	int j = 0;
	for (int i = 0; i < 4;) {
		if (mid_operator[i] > 0) {
			order.push_back(i);
			mid_operator[i]--;
		}
		else i++;
	}

	minval = calculate();
	maxval = minval;

	while (next_permutation(order.begin(), order.end())) {
		int now = calculate();
		minval = min(minval, now);
		maxval = max(maxval, now);
	}

	cout << maxval << "\n";
	cout << minval << "\n";

	return 0;
}