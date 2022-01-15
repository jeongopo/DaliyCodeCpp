#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int> arr;
	int input=0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	int sum = 0;
	int negativeIndex = n-1;
	int i = 0;
	for (i = n-1; i >=0; i--) {
		if (arr[i] > 0) {
			if (i > 0) {
				if (arr[i - 1] <= 1)	sum += arr[i];
				else {
					sum += arr[i]*arr[i - 1];
					i--;
				}
			}
			else sum += arr[i];
		}
		else {
			break;
		}
		//cout << i << "번째 sum : " << sum << "\n";
	}
	
	negativeIndex = i+1;
	//cout << "negativeIndex : " << negativeIndex << "\n";
	for (i = 0; i < negativeIndex; i++) {
		if (i < negativeIndex - 1) {
			sum += arr[i] * arr[i + 1];
			i++;
		}
		else sum += arr[i];
		//cout << i << "번째 sum : " << sum << "\n";
	}

	cout << sum << "\n";

}